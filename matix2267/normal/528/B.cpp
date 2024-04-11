#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 1000006;

int X[MAXN], W[MAXN];
pii E[MAXN];

void solve() {
	int n;
	scanf("%d",&n);
	fru(i,n) scanf("%d%d", &X[i], &W[i]);
	fru(i,n) E[i] = pii(X[i]-W[i], X[i]+W[i]);
	sort(E, E+n);
	int cur=-inft, ans=0;
	fru(i,n) {
		if(E[i].x >= cur) {
//			printf("taking %d %d\n", E[i].x, E[i].y);
			ans++;
			cur=E[i].y;
		} else {
//			printf("upd cur %d with %d\n", cur, E[i].y);
			cur=min(cur, E[i].y);
		}
	}
	printf("%d\n", ans);
}

int main() {
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int t=1;
//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}