#include <iostream>
#include <vector>
#include <algorithm>

struct WAT {
	int i;
	bool bridge;
	bool treasure;
	


	bool operator< (const WAT& oth) const {
		return i < oth.i;
	}
};

WAT make_WAT(int i, bool treasure) {
	WAT w;
	w.i = i;
	w.bridge = false;
	w.treasure = treasure;
	return w;
}

const int N = 3e5 + 1;
const int inf = 1e9 + 7;
std::vector<WAT> conns [N];
int prev[N];
int height[N];

int group[N];
bool arti[N];
std::vector<WAT> real [N];

bool result(int n, int e, int prev, bool treasure) {
	bool succ = false;
	treasure = treasure || arti[n];
	if (n == e) {
		succ = treasure;
	} else {
		for (int i = 0; i < real[n].size(); ++i) {
			int t = real[n][i].i;
			if (t != prev) {
				if (result(t, e, n, treasure || real[n][i].treasure)) {
					succ = true;
				}
			}
		}
	}
	return succ;
}
bool find(int n, int g) {
	for (int i = 0; i < conns[n].size(); ++i) {
		int t = conns[n][i].i;
		if (conns[n][i].bridge) {
			real[g].push_back(conns[n][i]);
		} else {
			if (conns[n][i].treasure) {
				arti[g] = true;
			}
			if (! group[t]) {
				group[t] = g;
				find(t, g);
			}
		}
	}
}

int min(int a, int b) {
	return a < b ? a : b;
}

int df(int n) {
	int h = inf;
	for (int i = 0; i < (int)conns[n].size(); ++i) {
		int t = conns[n][i].i;
		if (! prev[t]) {
			prev[t] = n;
			height[t] = height[n] + 1;
			int up = df(t);
			if (up > height[n]) {
				// Set the connection to a bridge
				conns[n][i].bridge = true;
				int low = 0;
				int high = conns[t].size() - 1;
				while(low != high) {
					int mid = (low + high) / 2;
					if (conns[t][mid].i >= n) {
						high = mid;
					} else {
						low = mid + 1;
					}
				}
				conns[t][low].bridge = true;
			}
			h = min(up, h);
		} else if (t != prev[n]) {
			h = min(h, height[t]);
		}
	}
	return h;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, m;
	std::cin >> n >> m;
	
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;
		conns[a].push_back(make_WAT(b, c));
		conns[b].push_back(make_WAT(a, c));
	}
	int s, e;
	std::cin >> s >> e;
	for (int i = 1; i <= n; ++i) {
		std::sort(conns[i].begin(), conns[i].end());
	}
	for (int i = 1; i <= n; ++i) {
		if (! prev[i]) {
			height[i] = 1;
			prev[i] = i;
			df(i);
		}
	}
	// Now we have to find connected components such that edges with edge.bridge == true are not considered.
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		if (! group[i]) {
			++count;
			arti[count] = false;
			group[i] = count;
			find(i, count);	
		}
	}
	for (int i = 1; i <= count; ++i) {
		for (int k = 0; k < real[i].size(); ++k) {
			real[i][k].i = group[real[i][k].i];
		}
	}
	
	s = group[s];
	e = group[e];
	std::cout << (result(s, e, 0, false) ? "YES" : "NO") << "\n";

}