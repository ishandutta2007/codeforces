#include <bits/stdc++.h>
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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=301000;
int n,k,a[N],s[N],avg,ps[N],ss[N],val[N],off[N];
map<int,VI> hs;
PII bf[N];
int q[N],vis[N],nval[N],p[N][20],rem[N],pr,T,mark[N];
VI ret;

void print(int x,VI y) {
	assert(SZ(y)==k);
	int s1=0,s2=0;
	printf("%d",x); for (auto p:y) printf(" %d",p);
	puts("");
	rep(i,0,k) s1+=a[(i+x)%n];
	rep(i,0,k) s2+=y[i];
	assert(s1==s2);
	rep(i,0,k) assert(y[i]>=0);
	rep(i,0,k) a[(i+x)%n]=y[i];
}

void gao(int l,int r) {
//	printf("gao %d %d\n",l,r);
	int len=(r-l+k-2)/(k-1);
	int cutoff=r-l;
	//printf()
	rep(i,0,len*(k-1)+1) {
		if (l+i>r) val[i]=0;
		else val[i]=a[(l+i)%n]-avg;
		off[i]=(a[(l+i)%n]-avg)-val[i];
	}
	int m=len*(k-1)+1;
	ps[0]=val[0]; ss[m-1]=val[m-1];
	rep(i,1,m) {
		ps[i]=ps[i-1]+val[i];
	}
	per(i,0,m-1) {
		ss[i]=ss[i+1]+val[i];
	}
	int t=0;
	auto add=[&](int bl) {
		if (vis[bl]) return;
		if (bf[bl].fi>=-avg&&bf[bl].se>=-avg) {
			q[t++]=bl;
			vis[bl]=1;
		}
	};
	rep(bl,0,len) {
		int pl=bl*(k-1);
		int pr=(bl+1)*(k-1);
		bf[bl]=mp(ss[pl],ps[pr]);
	//	printf("ooo %d %d\n",bf[bl].fi,bf[bl].se);
		vis[bl]=0;
		add(bl);
	}
	rep(i,0,t) {
		int bl=q[i];
		int pl=bl*(k-1);
		int pr=(bl+1)*(k-1);
		nval[pl]=bf[bl].fi; nval[pr]=bf[bl].se;
		rep(k,pl+1,pr) nval[k]=0;
		//printf("gg %d %d\n",pl,pr);
		VI xx;
		rep(k,pl,pr+1) {
			if (k>cutoff) xx.pb(a[(l+k)%n]);
			else {
				xx.pb(nval[k]+avg);
			}
			val[k]=nval[k];
		}
		print((pl+l)%n,xx);
		if (bl>0) {
			bf[bl-1].se=0;
			add(bl-1);
		}
		if (bl+1<len) {
			bf[bl+1].fi=0;
			add(bl+1);
		}
	}
}
int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,n) {
		scanf("%d",a+i);
		avg+=a[i];
	}
	assert(avg%n==0);
	avg/=n;
	rep(i,0,n) {
		s[i+1]=s[i]+a[i]-avg;
		hs[s[i]].pb(i);
	}
	int mr=n+1;
	for (auto q:hs) {
		VI z=q.se;
		int ss=0;
		int m=SZ(z);
		static int s[N],f[N];
		rep(i,0,m) {
			f[i]=z[i],f[i+m]=z[i]+n;
		}
		f[m+m]=z[0]+2*n;
		rep(i,0,m+m+1) s[i]=f[i]%(k-1);
		T++;
		per(i,0,2*m) {
			int w=(s[i]+1)%(k-1);
			if (mark[w]!=T) mark[w]=T,rem[w]=2*m;
			p[i][0]=rem[w];
			rem[s[i]]=i,mark[s[i]]=T;
		}
		rep(j,0,19) p[m+m][j]=m+m;
		rep(j,1,19) {
			rep(i,0,m+m) p[i][j]=p[p[i][j-1]][j-1];
		}
		rep(i,0,m) {
			int c=0,v=i;
			per(j,0,19) if (f[p[v][j]]<f[i]+n) {
				v=p[v][j]; c+=(1<<j);
			}
			ss=(f[v]-f[i]-c)/(k-1)+(f[i]+n-f[v]-1+k-2)/(k-1);
			if (ss<mr) {
				mr=ss;
				pr=z[i];
			}
		}
	}
	printf("%d\n",mr);
	int pv=0;
	ret.pb(pr);
	rep(j,1,n) {
		if (s[(pr+j)%n]==s[pr]&&(j-pv-1)%(k-1)==0) {
			ret.pb(pr+j);
			pv=j;
		}
	}
	ret.pb(pr+n);
	int zz=0;
	rep(i,0,SZ(ret)-1) {
		int l=ret[i+1]-ret[i];
		zz+=(l-1+k-2)/(k-1);
	}
	assert(zz==mr);
	rep(i,0,SZ(ret)-1) {
		gao(ret[i],ret[i+1]-1);
	}
	rep(i,0,n) assert(a[i]==avg);
}