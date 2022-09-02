#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

std::unordered_map<int, int> ind;

int p;

long long modpow(long long a, long long b) {
	if (b & 1) return (a * modpow(a, b-1)) % p;
	if (b == 0) return 1 % p;
	return modpow((a * a) % p, b/2);
}

int inv(int v) {
	int res = modpow(v, p-2);
	return res;
}

int invOp(int op) {
	if (op == 0) return 1;
	if (op == 1) return 0;
	if (op == 2) return 2;
}
int canInvOp(int op, bool side) {
	return (side ? invOp(op) : op);
}

int main() {
	int u,v;
	std::cin >> u >> v >> p;
	if (u == v) {
		std::cout << "0\n";
		return 0;
	}
	// Increment, Decrement, Take inverse
	std::vector<int> que;
	std::vector<bool> side;
	std::vector<int> prev;
	std::vector<int> move;
	prev = {-1, -1};
	side = {0, 1};
	que = {u, v};
	move = {-1, -1};
	ind[u] = 0;
	ind[v] = 1;

	int vals[2];
	vals[0] = -1;
	vals[1] = -1;
	int mid_move = -1;
	for (int j = 0; j < que.size(); ++j) {
		int x = que[j];
		std::vector<int> tars = {x+1, x-1, inv(x)};
		if (tars[0] == -1) tars[0] = p-1;
		if (tars[1] == p) tars[1] = 0;
		for (int i = 0; i < 3; ++i) {
			int t = tars[i];
			if (ind.find(t) == ind.end()) {
				ind[t] = que.size();

				que.push_back(t);
				side.push_back(side[j]);
				move.push_back(canInvOp(i, side[j]));
				prev.push_back(j);
			} else {
				int it = ind[t];
				if (side[it] != side[j]) {
					vals[side[it]] = it;
					vals[side[j]] = j;
					mid_move = canInvOp(i, side[j]);

					j = que.size();
					i = 3;
					break;
				}
			}
		}
	}

	std::vector<int> que1;
	std::vector<int> que2;
	int tmp = vals[0];
	while(tmp != -1) {
		que1.push_back(tmp);
		tmp = prev[tmp];
	}

	tmp = vals[1];
	while(tmp != -1) {
		que2.push_back(tmp);
		tmp = prev[tmp];
	}
	/*
	for (auto it : que1) std::cout << que[it] << ' '; std::cout << '\n';
	for (auto it : que2) std::cout << que[it] << ' '; std::cout << '\n';
	*/
	std::cout << (int)que1.size() + (int)que2.size() - 1 << '\n';
	for (int i = (int)que1.size() - 2; i >= 0; --i) {
		std::cout << (move[que1[i]] + 1) << ' ';
	}
	std::cout << (mid_move + 1) << ' ';
	for (int i = 0; i + 1 < que2.size(); ++i) {
		std::cout << (move[que2[i]] + 1) << ' ';
	}
	std::cout << '\n';
}