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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=(1<<22)+10;
int n,w,t,cnt,m;
bool mark[N],vis[N][2];
PII q[N*2];
void add(int s) {
	if (!vis[s][1]) {
		vis[s][1]=1;
		q[t++]=mp(s,1);
	}
	if (!vis[s][0]&&mark[s]) {
		vis[s][0]=1;
		q[t++]=mp(s,0);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d",&w);
		mark[w]=1;
	}
	rep(i,0,(1<<n)) if (!vis[i][0]&&mark[i]) {
		cnt++; t=0;
		q[t++]=mp(i,0);
		vis[i][0]=1;
		rep(i,0,t) {
			int u=q[i].fi,id=q[i].se;
			if (id==0) add((1<<n)-1-u);
			else {
				rep(j,0,n) if (u&(1<<j)) {
					add(u-(1<<j));
				}
			}
		}
	}
	printf("%d\n",cnt);
}