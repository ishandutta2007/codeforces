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

const int N=101000;
VI seq,mov,s[N];
int cnt,hs[N],dep[N],p[N],n;
void dfs(int u) {
	seq.pb(u);
	rep(i,0,cnt) {
		mov.pb(u);
	}
	cnt=0;
	for (auto v:s[u]) if (v!=hs[u]) dfs(v);
	if (hs[u]) dfs(hs[u]);
	cnt++;
}

int main() {
	scanf("%d",&n);
	dep[0]=1;
	rep(i,1,n) {
		scanf("%d",p+i);
		s[p[i]].pb(i);
		dep[i]=dep[p[i]]+1;
	}
	int z=max_element(dep,dep+n)-dep;
	int u=z;
	while (u) {
		hs[p[u]]=u;
		u=p[u];
	}
	dfs(0);
	rep(i,0,n) printf("%d%c",seq[i]," \n"[i==n-1]);
	printf("%d\n",SZ(mov));
	rep(i,0,SZ(mov)) printf("%d%c",mov[i]," \n"[i==SZ(mov)-1]);
}