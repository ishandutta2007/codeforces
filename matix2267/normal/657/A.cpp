#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

void solve() {
	int n,d,h;
	scanf("%d%d%d",&n,&d,&h);
	if(d > 2*h) return (void) puts("-1");
	if(d==1 && n>2) return (void) puts("-1");
	int cur=1, ne=2;
	fru(i,h) {
		printf("%d %d\n",cur,ne);
		cur = ne++;
	}
	cur=1;
	if(d!=h) fru(i,d-h) {
		printf("%d %d\n",cur,ne);
		cur = ne++;
	}
	while(ne <= n) printf("%d %d\n",1+(d==h),ne++);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}