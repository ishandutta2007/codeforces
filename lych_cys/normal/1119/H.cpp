#include<bits/stdc++.h>
#define ll long long
#define inf 1010000000
#define infll 1010000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 1000009
#define mod 998244353
using namespace std;

int n,m,tot,A,B,C,a[N],b[N],c[N],d[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int ksm(int x,int y){
	x=(x%mod+mod)%mod;
//	cerr<<x<<' '<<y<<'\n';
	int z=1; for (; y; y>>=1,x=(ll)x*x%mod) if (y&1) z=(ll)z*x%mod;
//	cerr<<z<<'\n';
	return z;
}
void fwt(int *a,int n){
	int i,j,k,x;
	for (i=1; i<n; i<<=1)
		for (j=0; j<n; j+=i<<1)
			for (k=j; k<j+i; k++){
				x=a[k];
				a[k]+=a[k+i]; a[k+i]=x-a[k+i];
			}
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&A,&B,&C); tot=1<<m;
	int i,j,k,x,y,z,t=0;
	for (i=1; i<=n; i++){
		scanf("%d%d%d",&x,&y,&z);
		t^=x; y^=x; z^=x;
		a[y]++; b[z]++; c[y^z]++;
	}
	fwt(a,tot); fwt(b,tot); fwt(c,tot);
	for (i=0; i<tot; i++){
		int t1=a[i],t2=b[i],t3=c[i];
		//cerr<<i<<'\n';
		//cerr<<a[i]<<' '<<b[i]<<' '<<c[i]<<'\n';
		int u=(n+t1)/2,v=(n+t2)/2,w=(n+t3)/2;
		//cerr<<u<<' '<<v<<' '<<w<<'\n';
		int q=(u+v+w-n)/2;
		u-=q; v-=q; w-=q;
		//cerr<<q<<' '<<u<<' '<<v<<' '<<w<<'\n';
		d[i]=(ll)ksm(((ll)A+B+C)%mod,q)%mod*ksm(A-B-C,w)%mod;
		d[i]=(ll)d[i]*ksm(A+B-C,u)%mod*ksm(A-B+C,v)%mod;
	}
	for (i=1; i<tot; i<<=1)
		for (j=0; j<tot; j+=i<<1)
			for (k=j; k<j+i; k++){
				x=d[k];
				ad(d[k],d[i+k]); d[i+k]=(x+mod-d[i+k])%mod;
			}
	for (i=0; i<tot; i++) d[i]=(ll)d[i]*ksm(tot,mod-2)%mod;
	for (i=0; i<tot; i++) printf("%d ",d[i^t]);
	puts("");
	return 0;
}