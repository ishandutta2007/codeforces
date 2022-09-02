#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
#include <algorithm>

typedef __gnu_pbds::tree<long long,__gnu_pbds::null_type,std::less<long long>,__gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

struct Station {
	long long x;
	long long r;
	long long f;

	Station() {
		x = 0;
		r = 0;
		f = 0;
	}

	Station(long long place, long long radius, long long frequence) {
		x = place;
		r = radius;
		f = frequence;
	}
};

struct Event {
	Station stat;
	bool add;

	Event(Station station, bool a) {
		stat = station;
		add = a;
	}

	bool operator< (const Event& other) const {
		if (add) {
			if (other.add) {
				return stat.x < other.stat.x;
			} else {
				return stat.x <= other.stat.x + other.stat.r;
			}
		} else {
			if (other.add) {
				return stat.x + stat.r < other.stat.x;
			} else {
				return stat.x + stat.r < other.stat.x + other.stat.r;
			}

		}
	}
};


ordered_set make_set() {
	ordered_set set;
	return set;
}

long long abs(long long a) {
	return a < 0 ? -a : a;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	long long n, k;
	std::cin >> n >> k;

	std::vector<Event> events;
	std::vector<long long> comp;
	std::vector<long long> freqs;
	std::vector<ordered_set> stats;
	
	long long a, b, c;
	for (int i = 0; i < n; ++i) {
		std::cin >> a >> b >> c;
		Station stat (a, b, c);
		Event add(stat, true);
		Event remove(stat, false);
		events.push_back(add);
		events.push_back(remove);
		comp.push_back(c);
	}
	std::sort(events.begin(), events.end());
	std::sort(comp.begin(), comp.end());
	freqs.push_back(comp[0]);
	stats.push_back(make_set());
	for (int i = 1; i < n; ++i) {
		if (comp[i] != comp[i-1]) {
			freqs.push_back(comp[i]);
			stats.push_back(make_set());
		}
	}
	long long pairs = 0;
	for (int i = 0; i < (int)events.size(); ++i) {
		Event e = events[i];
		if (e.add) {
			// Find colliding frequencies
			Station stat = e.stat;
			int low = 0;
			int high = freqs.size() - 1;
			while(low != high) {
				int mid = (low + high) / 2;
				if (freqs[mid] < stat.f - k) {
					low = mid + 1;
				} else {
					high = mid;
				}
			}
			int ind = low;
			while(abs(freqs[ind] - stat.f) <= k) {
				pairs += stats[ind].size() - stats[ind].order_of_key(stat.x - stat.r);
				++ind;
			}
			low = 0;
			high = freqs.size() - 1;
			while(low != high) {
				int mid = (low + high) / 2;
				if (freqs[mid] < stat.f) {
					low = mid + 1;
				} else {
					high = mid;
				}
			}
			stats[low].insert(stat.x);
		} else {
			Station stat = e.stat;
			int low = 0;
			int high = freqs.size() - 1;
			while(low != high) {
				int mid = (low + high) / 2;
				if (freqs[mid] < stat.f) {
					low = mid + 1;
				} else {
					high = mid;
				}
			}
			stats[low].erase(stats[low].find(stat.x));
		}	
	}
	std::cout << pairs << "\n";
}