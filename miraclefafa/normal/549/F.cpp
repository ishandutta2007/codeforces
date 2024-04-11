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

const int N=310000;
VI pos[1010000];
int stk[N],top,a[N],l[N],r[N],s[N];
int n,k;
const int K=1000010;
struct hash {
	int cmt[K],val[K]; int T;
	void init() { ++T;}
	inline void modify(int x,int p) {
		if (cmt[x]!=T) cmt[x]=T,val[x]=0;
		val[x]+=p;
	}
	inline int query(int x) {
		if (cmt[x]!=T) return 0; else return val[x];
	}
}hs[22];
int build() {
	int top=0;
	rep(i,1,n+1) {
		int k=top;
		while (k>0&&a[stk[k-1]]<a[i]) --k;
		if (k) r[stk[k-1]]=i;
		if (k<top) l[i]=stk[k];
		stk[k++]=i;
		top=k;
	}
	return stk[0];
}
ll ans;
void gao(int tl,int tr,int m,int dep) {
	if (tl>tr) return;
	a[m]%=k;
	if (m-tl<=tr-m) {
		rep(i,tl-1,m) hs[dep].modify(s[i],-1);
		rep(i,tl-1,m) ans+=hs[dep].query((s[i]+a[m])%k);
		hs[dep+1].init();
		rep(i,tl-1,m) hs[dep+1].modify(s[i],1);
		gao(tl,m-1,l[m],dep+1);
		gao(m+1,tr,r[m],dep);
	} else {
		rep(i,m,tr+1) hs[dep].modify(s[i],-1);
		rep(i,m,tr+1) ans+=hs[dep].query((s[i]+k-a[m])%k);
		hs[dep+1].init();
		rep(i,m,tr+1) hs[dep+1].modify(s[i],1);
		gao(m+1,tr,r[m],dep+1);
		gao(tl,m-1,l[m],dep);
	}
}
int main() {
	scanf("%d%d",&n,&k);
	hs[0].init();
	hs[0].modify(0,1);
	rep(i,1,n+1) {
		scanf("%d",a+i);
		s[i]=(s[i-1]+a[i])%k;
		hs[0].modify(s[i],1);
	}
	gao(1,n,build(),0);
	printf("%I64d\n",ans-n);
}