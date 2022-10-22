#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct Query {
	char c;
	int x;
};

int N;
vector<Query> Q;

int main() {
	cin >> N;
	Q.resize(2 * N);
	rep(i, 2 * N) {
		cin >> Q[i].c;
		if (Q[i].c == '+') Q[i].x = -1;
		else cin >> Q[i].x;
	}

	{
		deque<int> G;
		for (int i = 2 * N - 1; i >= 0; i--) {
			if (Q[i].c == '-') {
				G.push_back(i);
			}
			else {
				if (G.size() == 0) { cout << "NO" << endl; return 0; }
				int g = G.back(); G.pop_back();
				Q[i].x = Q[g].x;
			}
		}
	}

	{
		set<int> G;
		rep(i, 2 * N) {
			if (Q[i].c == '+') {
				G.insert(Q[i].x);
			}
			else {
				int x = *G.begin(); G.erase(x);
				if (x != Q[i].x) { cout << "NO" << endl; return 0; }
			}
		}
	}

	cout << "YES" << endl;
	bool spacing = false;
	rep(i, 2 * N) {
		if (Q[i].c == '+') {
			if (spacing) cout << " ";
			cout << Q[i].x;
			spacing = true;
		}
	}

	return 0;
}