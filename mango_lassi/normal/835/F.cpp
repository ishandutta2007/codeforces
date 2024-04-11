#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <deque>

struct double_deque {
	// int part is the timestamp of the elements' addition
	std::deque<std::pair<long long, int>> primary;
	std::deque<std::pair<long long, int>> secondary;

	double_deque() {

	}

	void add(std::pair<long long, int> el) {
		std::vector<std::pair<long long, int>> removed;
		while(! primary.empty()) {
			std::pair<long long, int> comp = primary.back();
			if (el.first >= comp.first) {
				primary.pop_back();
				removed.push_back(comp);
			} else {
				break;
			}
		}
		primary.push_back(el);
		if (! removed.empty()) {
			int last = removed.size()-1;
			while(! secondary.empty()) {
				if (removed[last].first >= secondary.back().first) {
					secondary.pop_back();
				} else {
					break;
				}
			}
			for (int i = last; i >= 0; --i) {
				secondary.push_back(removed[i]);
			}
		}
	}

	std::pair<std::pair<long long, int>, std::pair<long long, int>> get_largest() {
		std::pair<long long, int> largest;
		std::pair<long long, int> second_largest;
		if (! primary.empty()) {
			largest = primary.front();
		}
		if (primary.size() >= 2) {
			second_largest = primary[1];
		}
		if (! secondary.empty()) {
			if (secondary.front().first > second_largest.first) {
				second_largest = secondary.front();
			}
		}
		return {largest, second_largest};
	}

	void remove(int ind) {
		if (! primary.empty()) {
			if (primary.front().second == ind) {
				primary.pop_front();
			}
		}
		if (! secondary.empty()) {
			if (secondary.front().second == ind) {
				secondary.pop_front();
			}
		}
	}

	void print() {
		std::cout << "PRIMARY:";
		for (int i = 0; i < primary.size(); ++i) {
			std::cout << " (" << primary[i].first << ' ' << primary[i].second << ")";
		}
		std::cout << "\nSECONDARY:";
		for (int i = 0; i < secondary.size(); ++i) {
			std::cout << " (" << secondary[i].first << ' ' << secondary[i].second << ")";
		}
		std::cout << '\n';
	}
};


const int N = 2 * 1e5;
bool done [N];
std::vector<std::pair<int, int>> conns [N];

std::vector<int> find_cycle (int i, int p) {
	if (done[i]) {
		std::vector<int> res;
		res.push_back(i);
		return res;
	} else {
		done[i] = true;
		for (int j = 0; j < conns[i].size(); ++j) {
			int t =  conns[i][j].first;
			if (t != p) {
				std::vector<int> res = find_cycle(t, i);
				if (res.size() > 0) {
					if (res[res.size()-1] != -1) {
						if (res[0] == i) {
							res.push_back(-1);
						} else {
							res.push_back(i);
						}
					}
					return res;
				}
			}
		}
	}
	std::vector<int> empty;
	return empty;
}

// Longest path starting from this node, longest path in tree-cycle+this node
std::pair<long long, long long> dfs(int i, int p) {
	long long max_dist = 0;
	long long max_path = 0;
	for (int j = 0; j < conns[i].size(); ++j) {
		int t = conns[i][j].first;
		int d = conns[i][j].second;
		if (done[t] || t == p) continue;
		std::pair<long long, long long> res = dfs(t, i);
		max_path = std::max(max_path, res.second);
		max_path = std::max(max_path, max_dist + res.first + d);
		max_dist = std::max(max_dist, res.first + d);
	}
	return {max_dist, max_path};
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;
		--a; --b;
		conns[a].push_back({b,c});
		conns[b].push_back({a,c});
	}

	std::vector<int> cycle = find_cycle(0, 0);
	cycle.pop_back();

	for (int i = 0; i < n; ++i) {
		done[i] = false;
	}
	for (int i = 0; i < cycle.size(); ++i) {
		done[cycle[i]] = true;
		//std::cout << cycle[i] << ' ';
	}
	//std::cout << '\n';
	
	long long max_path = 0;
	std::vector<long long> max_dist;
	for (int i = 0; i < cycle.size(); ++i) {
		std::pair<long long, long long> vals = dfs(cycle[i], cycle[i]);
		max_dist.push_back(vals.first);
		//std::cout << vals.first << ' ';
		max_path = std::max(max_path, vals.second);
	}
	//std::cout << '\n';
	std::vector<long long> next_dist;
	for (int i = 0; i < cycle.size(); ++i) {
		for (int j = 0; j < conns[cycle[i]].size(); ++j) {
			int t = conns[cycle[i]][j].first;
			if (t == cycle[(i == cycle.size()-1 ? 0 : i+1)]) {
				next_dist.push_back(conns[cycle[i]][j].second);
				break;
			}
		}
	}
	double_deque lefts;
	double_deque rights;
	long long dist = 0;
	for (int i = 1; i < cycle.size(); ++i) {
		dist += next_dist[i];
	}
	for (int i = 1; i < cycle.size(); ++i) {
		lefts.add({max_dist[i] + dist, i});
		rights.add({max_dist[i] - dist, i});
		dist -= next_dist[i];
	}
	lefts.add({max_dist[0], cycle.size()});
	rights.add({max_dist[0], cycle.size()});
	long long min = 1e18;
	for (int i = 1; i < cycle.size(); ++i) {
		//std::cout << i << ", LEFTS:\n";
		//lefts.print();
		//std::cout << "RIGHTS\n";
		//rights.print();
		dist += next_dist[i-1];
		// Handle case
		auto lefts_res = lefts.get_largest();
		auto rights_res = rights.get_largest();
		long long offer = lefts_res.first.first + rights_res.first.first;
		if (lefts_res.first.second == rights_res.first.second) {
			offer = lefts_res.second.first + rights_res.first.first;
			offer = std::max(offer, lefts_res.first.first + rights_res.second.first);
		}
		/*
		if (offer < min) {
			std::cout << offer << ' ' << i << '\n';
			//std::cout << lefts_res.first.first << ' ' << lefts_res.first.second << ' ' << lefts_res.second.first << ' ' << lefts_res.second.second << '\n';
			//std::cout << rights_res.first.first << ' ' << rights_res.first.second << ' ' << rights_res.second.first << ' ' << rights_res.second.second << '\n';
		}
		*/
		min = std::min(min, offer);

		// Move barrier
		lefts.remove(i);
		rights.remove(i);
		lefts.add({max_dist[i] - dist, i + cycle.size()});
		rights.add({max_dist[i] + dist, i + cycle.size()});
	}
	// Handle case cycle.size()-1 to 0 is blocked
	auto lefts_res = lefts.get_largest();
	auto rights_res = rights.get_largest();
	long long offer = lefts_res.first.first + rights_res.first.first;
	if (lefts_res.first.second == rights_res.first.second) {
		offer = lefts_res.second.first + rights_res.first.first;
		offer = std::max(offer, lefts_res.first.first + rights_res.second.first);
	}
	min = std::min(min, offer);

	// Output result. We can't affect the value max_path :(
	std::cout << std::max(min, max_path) << '\n';
}