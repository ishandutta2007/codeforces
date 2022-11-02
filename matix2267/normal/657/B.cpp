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
	int n,k;
	scanf("%d%d",&n,&k);
	n++;
	vi V(n);
	fru(i,n) scanf("%d",&V[i]);
	vector<ll> W(n);
	int nz = -1;
	fru(i,n) W[i] = V[i];
	fru(i,n-1) {
		W[i+1] += W[i]/2;
		W[i] %= 2;
		if(W[i] && nz == -1) nz = i;
	}
	int ans = nz == -1 && W[n-1]-V[n-1] && abs(W[n-1]-V[n-1]) <= k;
	if(nz == -1) nz = n-2;
	for(int i=n-1; i>=0; i--) {
		W[i] = min(W[i], 2LL*k+1);
		W[i] = max(W[i],-2LL*k-1);
		//printf("dla %d (%d) byloby %lld\n",i,nz,-(W[i]-V[i]));
		if(i <= nz && abs(W[i]-V[i]) <= k) ans++;
		if(i) W[i-1] += W[i]*2;
	}
	printf("%d\n",ans);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}