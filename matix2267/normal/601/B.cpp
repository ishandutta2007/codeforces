#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
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
const int MAXN = 128*1024;

map<pii,ll> M;
pii A[2*MAXN];

pii getdrz(int a, int b) {
	a+=MAXN; b+=MAXN;
	pii ret = pii(-1,-1);
	while(a<=b) {
		if(a%2==1) ret = max(ret, A[a]);
		if(b%2==0) ret = max(ret, A[b]);
		a = (a+1)/2;
		b = (b-1)/2;
	}
	return ret;
}

ll getans(int a,int b) {
	if(a==b) return 0;
	if(a+1==b) return A[a+MAXN].x;
	map<pii,ll>::iterator iii = M.find(pii(a,b));
	if(iii != M.end()) return iii->y;
	pii z = getdrz(a,b-1);
	ll ret = 1LL*(z.y-a+1)*(b-z.y)*z.x + getans(a,z.y) + getans(z.y+1,b);
//	printf("ans %d %d -> %lld min@ %d %d -> %lld rec %d %d %d %d\n",a+1,b+1,ret,z.y+1,z.x,1LL*(z.y-a+1)*(b-z.y)*z.x,a+1,z.y+1,z.y+2,b+1);
	return M[pii(a,b)] = ret;
}

void solve() {
	int n,q;
	scanf("%d%d",&n,&q);
	int prev; scanf("%d",&prev);
	fru(i,n-1) {
		int next;
		scanf("%d",&next);
		A[i+MAXN] = pii(abs(next-prev), i);
		prev = next;
	}
	for(int i=MAXN-1; i>0; i--) A[i] = max(A[2*i], A[2*i+1]);
	while(q--) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		printf("%lld\n",getans(a,b));
	}
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}