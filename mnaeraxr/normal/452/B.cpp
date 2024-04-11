#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)3e5 + 10;

int n, m;
int X[4], Y[4];

inline int sqr(int v){
	return v * v;
}

double dist(int x1, int y1, int x2, int y2){
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

int m1[4] = {0, 0, 1, 1};
int m2[4] = {0, 1, 0, 1};
int d1[3] = {0, 0, 1};
int d2[3] = {0, 1, 0};

pii getPoint(int idx){
	int _m = idx / 3;
	int _d = idx % 3;
	int x = n * m1[_m] + d1[_d] * (m1[_m] ? -1 : 1);
	int y = m * m2[_m] + d2[_d] * (m2[_m] ? -1 : 1);
	if (x < 0 || x > n || y < 0 || y > m) return MP(0, 0);
	return MP(x, y);
}

double solve(vector<pii> V){
	for (int i = 0; i < 4; ++i){
		for (int j = i + 1; j < 4; ++j)
			if (V[i] == V[j]) return 0;
	}
	double ans = 0;
	for (int i = 0; i < 3; ++i)
		ans += dist(V[i].first, V[i].second, V[i + 1].first, V[i + 1].second);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	double best = 0;
	vector<pii> ans;

	for (int i = 0; i < (1 << 12); ++i){
		if (__builtin_popcount(i) != 4) continue;
		vector<pii> V;
		for (int j = 0; j < 12; ++j){
			if (i & (1 << j)){
				V.push_back(getPoint(j));
			}
		}
		sort(V.begin(), V.end());
		do{
			double cur = solve(V);
			if (cur > best){
				best = cur;
				ans = V;
			}
		} while(next_permutation(V.begin(), V.end()));
	}

	for (auto v : ans){
		cout << v.first << " " << v.second << endl;
	}

	return 0;
}