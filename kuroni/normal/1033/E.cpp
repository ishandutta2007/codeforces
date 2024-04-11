#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int qry(const std::vector<int> &a) {
	if(a.size() <= 1) {
		return 0;
	}
	std::cout << "? " << a.size() << std::endl;
	for(int i = 0; i < (int) a.size(); i++) {
		std::cout << a[i] + 1;
		if(i + 1 < (int) a.size()) {
			std::cout << ' ';
		} else {
			std::cout << std::endl;
		}
	}
	int x;
	std::cin >> x;
	return x;
}

int qry2(std::vector<int> a, int x) {
	//std::cout << "qry2 " << x << std::endl;
	int ans = -qry(a);
	a.push_back(x);
	ans += qry(a);
	return ans;
}

int get(int x, std::vector<int> rest) {
	if(rest.size() == 1) {
		return rest[0];
	}
	int mid = (int) rest.size() / 2;
	std::vector<int> l(rest.begin(), rest.begin() + mid), r(rest.begin() + mid, rest.end());
	if(qry2(l, x)) {
		return get(x, l);
	} else {
		return get(x, r);
	}
}

int dist[666];
std::vector<int> edges[666];
std::vector<int> path;

bool dfs(int on, int par, int want) {
	if(on == want) {
		path.push_back(on);
		return true;
	}
	for(auto to : edges[on]) {
		if(to == par) continue;
		if(dfs(to, on, want)) {
			path.push_back(on);
			return true;
		}
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> rest;
	std::vector<int> q;
	for(int i = 1; i < n; i++) {
		rest.push_back(i);
	}
	q.push_back(0);
	for(int i = 0; i < (int) q.size(); i++) {
		int on = q[i];
		int size = qry2(rest, on);
		//std::cout << i << " has " << size << " edges to outside" << std::endl;
		while(size--) {
			int to = get(on, rest);
			//std::cout << "found edge (" << on << ", " << to << ")" << std::endl;
			edges[on].push_back(to);
			edges[to].push_back(on);
			q.push_back(to);
			rest.erase(std::lower_bound(rest.begin(), rest.end(), to));
			dist[to] = dist[on] ^ 1;
		}
	}
	std::vector<int> partitions[2];
	for(int i = 0; i < n; i++) {
		partitions[dist[i]].push_back(i);
	}
	for(int rep = 0; rep < 2; rep++) {
		if(qry(partitions[0])) {
			auto part = partitions[0];
			for(int i = (1 << 10); i > 0; i /= 2) {
				if(i < (int) part.size()) {
					std::vector<int> p(part.begin(), part.end() - i);
					if(qry(p)) {
						part.swap(p);
					}
				}
			}
			for(int i = (1 << 10); i > 0; i /= 2) {
				if(i < (int) part.size()) {
					std::vector<int> p(part.begin() + i, part.end());
					if(qry(p)) {
						part.swap(p);
					}
				}
			}
			//std::cout << "extra edge between " << part[0] << ", " << part.back() << std::endl;
			dfs(part[0], -1, part.back());
			std::cout << "N " << path.size() << std::endl;
			for(int i = 0; i < (int) path.size(); i++) {
				std::cout << path[i] + 1;
				if(i + 1 < (int) path.size()) {
					std::cout << ' ';
				} else {
					std::cout << std::endl;
				}
			}
			return 0;
		}
		partitions[0].swap(partitions[1]);
	}
	path = partitions[0];
	std::cout << "Y " << path.size() << std::endl;
	for(int i = 0; i < (int) path.size(); i++) {
		std::cout << path[i] + 1;
		if(i + 1 < (int) path.size()) {
			std::cout << ' ';
		} else {
			std::cout << std::endl;
		}
	}
	return 0;
}