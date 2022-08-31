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
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

#include <ctime>
const int N=3010;
int n,m,p,s[N],fst[2*N],nxt[N];
int g[N][N];
PII c[N],y[N];

int main() {
	scanf("%d%d",&n,&m);
	p=n*(n-1);
	rep(i,0,m) {
		scanf("%d",s+i);
		p-=s[i];
	}
	if (p<0) {
		puts("no");
		return 0;
	}
	if (n==m) {
		if (p!=0) { puts("no"); return 0;}
	} else {
		int v=n-m,c=p/v;
		rep(i,m,m+p%v) s[i]=c+1;
		rep(i,m+p%v,n) s[i]=c;
	}
	p=0;
	rep(i,0,n-1) if (s[i]<s[i+1]) { puts("no"); return 0;}
	rep(i,0,n) {
		p+=s[n-i-1];
		if (p<i*(i+1)) { puts("no"); return 0;}
	}
	puts("yes");
	rep(i,0,n) c[i]=mp(s[i],i);
	rep(i,0,n) {
		int u=c[i].se;
		per(j,i+1,n) {
			int v=c[j].se;
			if (c[i].fi>=2) {
				c[i].fi-=2;
				g[u][v]=2; g[v][u]=0;
			} else if (c[i].fi==1) {
				c[i].fi-=1; c[j].fi-=1;
				g[u][v]=g[v][u]=1;
			} else {
				c[j].fi-=2;
				g[v][u]=2; g[u][v]=0;
			}
		}
		rep(j,0,2*n+1) fst[j]=-1;
		int tot=0;
		rep(j,i+1,n) {
			assert(c[j].fi>=0);
			y[tot]=c[j]; nxt[tot]=fst[c[j].fi]; fst[c[j].fi]=tot; ++tot;
		}
		int v=i+1;
		per(j,0,2*n+1) for (int k=fst[j];k!=-1;k=nxt[k]) c[v++]=y[k];
	}
	rep(i,0,n) {
		int pp=0;
		rep(j,0,n) if (i==j) putchar('X'); else {
			if (g[i][j]==2) putchar('W'); else if (g[i][j]==1) putchar('D'); else putchar('L');
			pp+=g[i][j];
			assert(g[i][j]+g[j][i]==2);
		}
		assert(pp==s[i]);
		puts("");
	}
}

/*
bool check() {
	p=n*(n-1);
	rep(i,0,m) p-=s[i];
	if (p<0) return 0;
	if (n==m) {
		if (p!=0) return 0;
	} else {
		int v=n-m,c=p/v;
		rep(i,m,m+p%v) s[i]=c+1;
		rep(i,m+p%v,n) s[i]=c;
	}
	p=0;
	rep(i,0,n) {
		p+=s[n-i-1];
		if (p<i*(i+1)) return 0;
	}
	return 1;
}
bool check2() {
	int sum=0;
	rep(i,0,n) {
		if (i<m) {
			s[i]-=n-1;
		} else {
			s[i]=min(s[i-1],(i+1)*(n-i-1)-sum);
		}
		sum+=s[i];
		if (sum>(i+1)*(n-i-1)) {
			return 0;
		}
	}
	return 1;
}
int main() {
	while (1) {
		n=3000,m=rand()%3000+1;	
		rep(i,0,m) s[i]=rand()%(2*n+1);
		sort(s,s+m); reverse(s,s+m);
		bool v1=check();
		bool v2=check2();
		assert(v1==v2);
		printf("%d %d\n",v1,v2);
	}
}*/