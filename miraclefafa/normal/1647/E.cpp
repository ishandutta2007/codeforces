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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int go[33][N],vis[N];
int n,a[N],ret[N];
VI vpos[N],rpos[N];
int main() {
	scanf("%d",&n);
	set<int> st;
	for (int i=1;i<=n;i++) {
		scanf("%d",&go[0][i]);
		st.insert(go[0][i]);
	}
	rep(i,1,n+1) {
		scanf("%d",a+i);
	}
	int maxid=*max_element(a+1,a+n+1);
	int rd=(maxid-n)/(n-SZ(st));
	rep(i,1,30) rep(j,1,n+1)
		go[i][j]=go[i-1][go[i-1][j]];
	rep(i,1,n+1) {
		int pos=i;
		rep(j,0,30) if (rd&(1<<j)) pos=go[j][pos];
		//printf("zz %d %d\n",i,pos);
		vpos[pos].pb(i);
	}
	rep(i,1,n+1) if (a[i]<=n) {
		ret[vpos[i][0]]=a[i];
		vis[a[i]]=1;
		rep(j,1,SZ(vpos[i])) rpos[a[i]].pb(vpos[i][j]);
	}
	set<int> xpos;
	rep(i,1,n+1) {
		if (!vis[i]) {
			int v=*xpos.begin();
			ret[v]=i;
			xpos.erase(v);
		}
		for (auto x:rpos[i]) xpos.insert(x);
	}
	rep(i,1,n+1) printf("%d ",ret[i]); puts("");
}