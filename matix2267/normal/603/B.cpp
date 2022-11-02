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

int qpow(int a, int b) {
	int w = 1;
	while(b) {
		if(b%2) w = 1LL*w*a % mod;
		a = 1LL*a*a % mod;
		b/=2;
	}
	return w;
}

char vis[MAXN];

void solve() {
	int p,k,ans=1;
	scanf("%d%d",&p,&k);
	if(k!=1) vis[0]=1;
	fru(s,p) if(!vis[s]) {
		ans=1LL*ans*p % mod;
		for(int x = s; !vis[x]; x = 1LL*x*k%p) vis[x]=1;
	}
//	if(k==0) printf("%d\n", qpow(p,p-1));
//	else if(k==1) printf("%d\n", qpow(p,p));
//	else if(k==p-1) printf("%d\n", qpow(p,p/2));
//	else printf("%d\n", p);
	printf("%d\n",ans);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}