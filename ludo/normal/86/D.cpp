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

const int maxn = 1e6 + 1;

int n, t, sqn, A[maxn];

struct QRY {
	int l, r, i;
} Q[maxn];

bool operator<(QRY a, QRY b) {
	int cla = a.l / sqn;
	int clb = b.l / sqn;
	if (cla != clb) return cla < clb;
	if (a.r != b.r) return a.r < b.r;
	return a.l < b.l;
}

int cnt[maxn] = {};
ll curans = 0, ans[maxn]; 
void expand(int i) {
	int v = A[i];
	curans += 1LL * v * (2 * cnt[v]++ + 1);
}

void shrink(int i) {
	int v = A[i];
	curans += 1LL * v * (-2 * cnt[v]-- + 1);
}

int main()
{
	scanf("%d%d", &n, &t);
	sqn = sqrt(n);

	REP(i, n) scanf("%d", &A[i+1]);
	REP(i, t) scanf("%d%d", &Q[i].l, &Q[i].r), Q[i].i = i;

	sort(Q, Q + t);

	int ql = 1, qr = 0;
	REP(i, t) { 
		int curl = Q[i].l, curr = Q[i].r;
		while (qr < curr) expand(++qr);
		while (qr > curr) shrink(qr--);

		while (ql > curl) expand(--ql);
		while (ql < curl) shrink(ql++);

		ans[Q[i].i] = curans;
	}

	REP(i,t) printf("%lld\n", ans[i]);

	return 0;
}