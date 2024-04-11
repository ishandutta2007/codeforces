#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

// const int MN = 1<<18;
int n, k, A[1<<18][5];
int MN;

// max-segment-tree
int st[32][1<<19];
int lg2[33];

void update(int i)
{
	i += MN;
	st[0][i] = 0;
	REP(j, k) st[0][i] += A[i-MN][j];
	rep(m,1,(1<<k)) {
		int lb = m & -m;
		st[m][i] = st[m^lb][i] - 2 * A[i-MN][lg2[lb]];
	}

	// REP(j, k) cerr << A[i][j] << " ";
	// cerr << "UPD: " << st[0][i] << " " << st[1][i] << " " << st[2][i] << st[3][i] << endl;
	while ((i/=2) > 0) {
		REP(m, 1<<k) st[m][i] = max(st[m][2*i], st[m][2*i+1]);
	}
}

int query(int m, int b, int e)
{
	int ret = -1e9;
	for (b += n, e += n; b < e; b /= 2, e /= 2) {
		if (b % 2) ret = max(ret, st[m][b++]);
		if (e % 2) ret = max(ret, st[m][--e]);
	}
	return ret;
}

// [l, r)
int query(int l, int r)
{
	int ret = -2e9;
	REP(m, 1<<(k-1)) {
		int mp = ~m & ((1<<k) - 1);
		// cerr << m << "," << mp << ": " << query(m, l, r) << " " << query(mp, l, r) << endl;
		ret = max(ret, query(m, l, r) + query(mp, l, r));
	}
	return ret;
}

int main()
{
	for (int i = 0; i <= 5; i++) lg2[1<<i]=i;

	scanf("%d%d",&n,&k);
	REP(i,n)REP(j,k) scanf("%d",&A[i][j]);

	// hack:
	MN = n;

	REP(i, n) {
		st[0][MN + i] = 0;
		REP(j, k) st[0][MN+i] += A[i][j];
		rep(m,1,(1<<k)) {
			int lb = m & -m;
			st[m][MN+i] = st[m^lb][MN+i] - 2 * A[i][lg2[lb]];
		}
	}

	// build tree
	REP(m, 1<<k) {
		for (int i = MN; --i > 0; )
			st[m][i] = max(st[m][2*i], st[m][2*i+1]);
	}

	int q, op, ql, qr;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &op);
		if (op == 1) {
			int idx;
			scanf("%d", &idx);
			--idx;
			REP(j, k) scanf("%d", &A[idx][j]);
			update(idx);
		} else {
			scanf("%d%d", &ql, &qr);
			printf("%d\n", query(ql - 1, qr));
		}
	}

	return 0;
}