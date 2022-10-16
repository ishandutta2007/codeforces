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
const int MAXN = (int)4e5 + 10;

struct ST{
	int data[MAXN << 2];
	void update(int p, int b, int e, int x, int y, int v){
		if (x <= b && e <= y) data[p] = max(data[p], v);
		else{
			int mid = (b + e) >> 1;
			int le = p << 1;
			int ri = le | 1;
			if (x <= mid) update(le, b, mid, x, y, v);
			if (mid + 1 <= y) update(ri, mid + 1, e, x, y, v);
		}
	}

	int query(int p, int b, int e, int x){
		if (b == e) return data[p];
		int mid = (b + e) >> 1;
		int le = p << 1;
		int ri = le | 1;
		int ans = x <= mid ? query(le, b, mid, x) : query(ri, mid + 1, e, x);
		return max(data[p], ans);
	}
} S1, S2;

int T[MAXN], t;
int X[MAXN], Y[MAXN];
bool D[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	t = 0;

	int n, m;
	cin >> n >> m;

	T[t++] = 0;
	for (int i = 0; i < m; ++i){
		cin >> X[i] >> Y[i];
		char c; cin >> c;
		D[i] = c == 'U';
		T[t++] = X[i];
		T[t++] = Y[i];
	}

	sort(T, T + t);
	t = unique(T, T + t) - T;

	for (int i = 0; i < m; ++i){
		int x = lower_bound(T, T + t, X[i]) - T;
		int y = lower_bound(T, T + t, Y[i]) - T;
		int ans = -1;
		if (D[i]){
			int f = S1.query(1, 0, t, x);
			ans = T[y] - T[f];
			if (f < y) S2.update(1, 0, t, f + 1, y, x);
			S1.update(1, 0, t, x, x, y);
		}
		else{
			int f = S2.query(1, 0, t, y);
			ans = T[x] - T[f];
			if (f < x) S1.update(1, 0, t, f + 1, x, y);
			S2.update(1, 0, t, y, y, x);
		}

		cout << ans << endl;
	}

	return 0;
}