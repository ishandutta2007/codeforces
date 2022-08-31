#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const double pi=acos(-1.);
struct CD {
	double a,b;
	CD() {}
	CD(double a,double b):a(a),b(b) {}
};
inline CD operator+(CD &a, CD &b) { return CD(a.a+b.a,a.b+b.b);}
inline CD operator-(CD &a, CD &b) { return CD(a.a-b.a,a.b-b.b);}
inline CD operator*(CD &a, CD &b) { return CD(a.a*b.a-a.b*b.b,a.b*b.a+a.a*b.b);}
const int N=80100;
int r[N],n,m,x,t;
int g[110][110];
CD tmp[N],P[N],Q[N];
double dp[60][N],E[110][N],p[N],q[N],sprob[110][N/4],prob[110][N/4];
int a[110],b[110],c[110],pp;
void rev(CD *a,int n) {
	r[0]=0;
	rep(i,1,n) if (i&1) r[i]=(r[i>>1]>>1)+(n>>1); else r[i]=(r[i>>1]>>1);
	rep(i,0,n) if (r[i]<i) swap(a[r[i]],a[i]);
}
void dft(CD* a,int n,bool inv) {
	CD wi,w,u,v;
	rev(a,n);
	for (int m=2;m<=n;m<<=1) {
		double Arg=2*pi/m*(inv?-1:1);
		wi=CD(cos(Arg),sin(Arg));
		for (int j=0;j<n;j+=m) { w=CD(1,0);
			for (int k=j,k2=j+m/2;k2<j+m;k++,k2++)
				u=a[k],v=a[k2]*w,a[k]=u+v,a[k2]=u-v,w=w*wi;
		}
	}
	if (inv) for (int j=0;j<n;j++) a[j].a/=n;
}
vector<CD> qq[110][30];
double pmt[N];
void mul(int n,int j) {
	if (n<32) {
		rep(i,0,n) pmt[i]=0;
		rep(i,0,n/2) if (p[i]) rep(j,0,n/2) pmt[i+j]+=p[i]*q[j];
		rep(i,0,n) tmp[i]=CD(pmt[i],0);
		return;
	}
	rep(i,0,n) P[i]=CD(p[i],0);
	dft(P,n,0);
	int r=0;
	while ((1<<r)!=n) r++;
	if (SZ(qq[j][r])==0) {
		rep(i,0,n) Q[i]=CD(q[i],0);
		dft(Q,n,0);
		rep(i,0,n) qq[j][r].pb(Q[i]);
	}
	rep(i,0,n) tmp[i]=P[i]*qq[j][r][i];
	dft(tmp,n,1);
}
void solve(int l,int r) {
	if (l+1==r) {
		if (l==0) rep(i,1,n) dp[i][0]=x+g[i][n];
		else {
			rep(i,1,n) dp[i][l]=1e30;
			rep(i,0,m) if (b[i]!=n) dp[a[i]][l]=min(dp[a[i]][l],E[i][l]+sprob[i][l+1]*(x+g[b[i]][n])+c[i]);
				else dp[a[i]][l]=min(dp[a[i]][l],E[i][l]+sprob[i][l+1]*(x+g[b[i]][n])+c[i]);
		}
		return;
	}
	if (l>t) return;
	int md=(l+r)>>1;
	solve(l,md);
	rep(j,0,m) {
		rep(i,0,2*(r-l)) p[i]=q[i]=0;
		rep(i,0,md-l) p[i]=dp[b[j]][i+l];
		rep(i,0,r-l) q[i]=prob[j][i];
		mul(2*(r-l),j);
		rep(i,md,r) E[j][i]=E[j][i]+tmp[i-l].a;
	}
	solve(md,r);
}
int main() {
	scanf("%d%d%d%d",&n,&m,&t,&x);
	rep(i,1,n+1) rep(j,1,n+1) g[i][j]=(i==j)?0:(1<<29);
	rep(i,0,m) {
		scanf("%d%d%d",a+i,b+i,c+i);
		g[a[i]][b[i]]=min(g[a[i]][b[i]],c[i]);
		rep(j,1,t+1) scanf("%d",&pp),prob[i][j]=pp*0.00001;
		per(j,0,t+1) sprob[i][j]=sprob[i][j+1]+prob[i][j];
	}
	rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	int M=1; while (M<=t) M*=2; 
	solve(0,M);
	printf("%.10f\n",dp[1][t]);
}