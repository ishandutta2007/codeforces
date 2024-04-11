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
//const ll mod=1000000007;
//ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const ll mod1=1000000007,mod2=1000000009;
ll base1=((rand()<<14)+rand())%1000000000,base2=((rand()<<14)+rand())%1000000000;

const int N=201000;
pair<ll,ll> th[30][N],sh[30][N],sd[N];
int ts[30][N],ss[30][N];
int n,m,mt[30],bp[30];
char s[N],t[N];
VI ans;
void build(pair<ll,ll> *a,int *b,int m) {
	rep(i,1,m+1) a[i]=mp((a[i-1].fi*base1+b[i])%mod1,(a[i-1].se*base2+b[i])%mod2);
}
pair<ll,ll> geth(pair<ll,ll> *a,int l,int r) {
	ll h1=(a[r].fi-a[l-1].fi*sd[r-l+1].fi)%mod1;
	ll h2=(a[r].se-a[l-1].se*sd[r-l+1].se)%mod2;
	if (h1<0) h1+=mod1; if (h2<0) h2+=mod2;
	return mp(h1,h2);
}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1); scanf("%s",t+1);
	sd[0]=mp(1,1);
	rep(i,1,200001) sd[i]=mp(sd[i-1].fi*base1%mod1,sd[i-1].se*base2%mod2);
	rep(j,0,26) {
		rep(i,1,m+1) {
			ts[j][i]=(t[i]==j+'a');
			if (t[i]==j+'a') bp[j]=i;
		}
		build(th[j],ts[j],m);
	}
	rep(j,0,26) {
		rep(i,1,n+1) ss[j][i]=(s[i]==j+'a');
		build(sh[j],ss[j],n);
	}
	rep(i,1,n-m+2) {
		rep(j,0,26) mt[j]=-1;
		rep(j,0,26) if (bp[j]!=0) mt[j]=s[i+bp[j]-1]-'a';
		bool fg=1;
		rep(j,0,26) if (mt[j]!=-1&&mt[j]!=j) {
			if (mt[mt[j]]!=-1) { if (mt[mt[j]]!=j) fg=0;}
			else mt[mt[j]]=j;
		}
		// how to check form a pair
		if (fg) {
			rep(j,0,26) if (mt[j]!=-1) {
				fg&=geth(th[j],1,m)==geth(sh[mt[j]],i,i+m-1);
			}
		}
		if (fg) ans.pb(i);
	}
	printf("%d\n",SZ(ans));
	for (auto i:ans) printf("%d ",i);
}