#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)2e5 + 10;

pii P[MAXN];
int R[MAXN];
int n, m;

int __nxt(int idx, int l, bool d){
	int r = -1;
	if (d) r = upper_bound(P, P + n, (pii){P[idx].first + l, oo}) - P - 1;
	else r = lower_bound(P, P + n, (pii){P[idx].first - l, 0}) - P;
	return r;
}

int nxt(int idx, int l, bool d){
	int r = __nxt(idx, l, d);
	if (r == idx) r = __nxt(idx, l, !d);
	return r;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	if (n == 1){
		for (int i = 0; i < m; ++i)
			cout << 1 << endl;
		exit(0);
	}

	for (int i = 0; i < n; ++i){
		cin >> P[i].first;
		P[i].second = i + 1;
	}

	sort(P, P + n);
	for (int i = 0; i < n; ++i){
		R[P[i].second] = i;
	}

	for (int i = 0; i < m; ++i){
		int idx, l;	cin >> idx >> l;
		idx = R[idx];
		bool d = true;

		int r = nxt(idx, l, d);
		if (r == idx){
			cout << P[idx].second << endl;
			continue;
		}
		d = r < idx;
		l -= abs(P[idx].first - P[r].first);
		idx = r;

		while (true){
			r = nxt(idx, l, d);
			if (r == idx) break;
			int len = abs(P[idx].first - P[r].first);
			int times = l / len;
			l = l % len;
			if (times & 1){
				d = !d;
				idx = r;
			}

		}

		cout << P[idx].second << endl;
	}

	return 0;
}