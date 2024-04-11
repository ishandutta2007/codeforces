#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int64 D1[maxn];
int64 D2[maxn];
int64 X[maxn];
int64 Y[maxn];
int64 T[maxn];

map<int64,vi> DD1;
map<int64,vi> DD2;

bool corner(int64 x, int64 y, int64 n, int m){
	return (x == n || x == 0) && (y == m || y == 0);
}

int n, m;

vector<pii> getBorder(int64 d, int64 t){
	vector<pii> C;
	if (t == 1){
		C = {{0, -d}, {n, n - d}, {d, 0}, {m + d, m}};
	}
	else{
		C = {{0, d}, {n, d - n}, {d, 0}, {d - m, m}};
	}

	vector<pii> A;

	for (auto pp : C){
		if (0 <= pp.first && pp.first <= n && 0 <= pp.second && pp.second <= m)
			A.push_back(pp);
	}

	return A;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 k;

	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i){
		cin >> X[i] >> Y[i];
		D1[i] = X[i] - Y[i];
		D2[i] = X[i] + Y[i];

		DD1[D1[i]].push_back(i);
		DD2[D2[i]].push_back(i);
	}

	int64 x = 0, y = 0, t = 0;
	int64 s = 0;

	do{
		int64 px = x;

		if (t == 0){
			int64 diag = x - y;

			for (auto e : DD1[diag]){
				int64 diff = abs(x - X[e]);
				if (T[e] == 0)
					T[e] = s + diff;
			}

			vector<pii> border = getBorder(diag, 1);

			for (auto pp : border){
				if (x == pp.first && y == pp.second)
					continue;

				x = pp.first, y = pp.second;
				break;
			}
		}
		else{
			int diag = x + y;

			for (auto e : DD2[diag]){
				int64 diff = abs(x - X[e]);
				if (T[e] == 0)
					T[e] = s + diff;
			}

			vector<pii> border = getBorder(diag, 2);

			for (auto pp : border){
				if (x == pp.first && y == pp.second)
					continue;

				x = pp.first, y = pp.second;
				break;
			}
		}

		t ^= 1;
		s += abs(x - px);

	} while (!corner(x, y, n, m));

	for (int64 i = 0; i < k; ++i){
		if (T[i] == 0) cout << -1 << endl;
		else cout << T[i] << endl;
	}

	return 0;
}