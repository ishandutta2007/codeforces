#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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


const int SX = 1024, MX = 2e5 + SX + SX;

int a[MX], b[MX];

int buk[MX/SX][MX];

void inc(int i, int j) { j++;
	while (j < MX) buk[i][j]++, j += j & -j; }
void dec(int i, int j) { j++;
	while (j < MX) buk[i][j]--, j += j & -j; }
int q(int i, int j) {
	int r = 0; while (j > 0) r += buk[i][j], j -= j & -j;
	return r; }

int ret[MX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	scanf("%d%d",&n,&m);
	REP(i,n)scanf("%d",&a[i]);
	REP(i,n)scanf("%d",&b[i]);

	vi inv(n);
	REP(i, n) inv[a[i] - 1] = i;
	REP(i, n) b[i] = inv[b[i] - 1];

	REP(i, n) inc(i/SX, b[i]);

	int nq = 0;
	REP(i,m){
		int op;
		scanf("%d",&op);
		if (op == 1) {
			// query
			int la, ra, lb, rb;
			scanf("%d%d%d%d", &la, &ra, &lb, &rb);
			la--; lb--;

			int &ans = ret[nq++];
			ans = 0;

			if (lb % SX != 0) {
				int steps = min((-lb) % SX + SX, rb - lb);
				while (steps--) {
					ans += la <= b[lb] && b[lb] < ra;
					lb++;
				}
			}
			while (lb + SX <= rb) {
				ans += q(lb/SX, ra) - q(lb/SX, la);
				lb += SX;
			}
			while (lb < rb) {
				ans += la <= b[lb] && b[lb] < ra;
				lb++;
			}
		} else {
			// swap
			int x, y;
			scanf("%d%d", &x, &y);
			--x; --y;
			
			dec(x/SX, b[x]); dec(y/SX, b[y]);
			swap(b[x], b[y]);
			inc(x/SX, b[x]); inc(y/SX, b[y]);
		}

		// REP(j, n) cerr << b[j]; cerr << endl;
	}

	REP(i, nq) printf("%d\n", ret[i]);
	return 0;
}