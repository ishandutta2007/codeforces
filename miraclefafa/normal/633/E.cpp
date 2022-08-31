#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=1000100;
int n,k;
int v[N],c[N],len[N],pv[N][21],pc[N][21],p[N];
double fac[N],ret;
int queryv(int l,int r) {
	int d=len[r-l+1];
	return max(pv[l][d],pv[r-(1<<d)+1][d]);
}
int queryc(int l,int r) {
	int d=len[r-l+1];
	return min(pc[l][d],pc[r-(1<<d)+1][d]);
}
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) scanf("%d",v+i);
	rep(i,1,n+1) scanf("%d",c+i);
	len[1]=0;
	rep(i,2,n+1) len[i]=len[i>>1]+1;
	rep(i,1,n+1) pv[i][0]=v[i],pc[i][0]=c[i];
	rep(j,1,20) rep(i,1,n+2-(1<<j)) {
		pv[i][j]=max(pv[i][j-1],pv[i+(1<<(j-1))][j-1]);
		pc[i][j]=min(pc[i][j-1],pc[i+(1<<(j-1))][j-1]);
	}
	rep(i,1,n+1) {
		int l=i,r=n;
		while (l+1<r) {
			int md=(l+r)>>1;
			if (100*queryv(i,md)<queryc(i,md)) l=md;
			else r=md;
		}
		p[i]=min(100*queryv(i,l),queryc(i,l));
		p[i]=max(p[i],min(100*queryv(i,r),queryc(i,r)));
//		printf("%d\n",p[i]);
	}
	sort(p+1,p+n+1);
	rep(i,1,n+1) fac[i]=fac[i-1]+log(i);
	rep(i,1,n+1) if (k-1<=n-i) {
		ret+=p[i]*exp(fac[n-i]-fac[n-i-k+1]-fac[k-1]-fac[n]+fac[k]+fac[n-k]);
//		p[i]*comb[n-i][k-1]/comb[n][k];
	}
	printf("%.10f\n",ret);
}