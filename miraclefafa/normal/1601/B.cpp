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

const int N=301000;
int n,a[N],b[N],d[N];
PII pre[N];
queue<int> q;
set<int> s;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) scanf("%d",b+i);
	rep(i,0,n) d[i]=1<<30;
	rep(i,0,n+2) s.insert(i);
	d[n]=0;
	q.push(n);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		while (1) {
			auto x=*s.lower_bound(u-a[u]);
			if (x>u) break;
			s.erase(x);
			int v=x+b[x];
			if (d[v]>d[u]+1) {
				//printf("ffff %d %d\n",u,v);
				d[v]=d[u]+1;
				pre[v]={u,x};
				q.push(v);
			}
		}
	}
	//puts("");
	if (d[0]==1<<30) {
		puts("-1"); return 0;
	}
	int x=0;
	VI ans;
	while (x!=n) {
		ans.pb(pre[x].se);
		x=pre[x].fi;
	}
	printf("%d\n",SZ(ans));
	reverse(all(ans));
	for (auto x:ans) printf("%d ",x); puts("");
}