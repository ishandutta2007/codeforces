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

const int N=1010;
int n,m,b[N],c[N],pre[N],vis[N],ret;
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%d",b+i);
	rep(i,0,m) scanf("%d",c+i);
	rep(i,1,n+1) pre[i]=-1;
	rep(i,0,m) {
		memset(vis,0,sizeof(vis));
		rep(j,pre[c[i]]+1,i) {
			if (vis[c[j]]==0) ret+=b[c[j]],vis[c[j]]=1;
		}
		pre[c[i]]=i;
	}
	printf("%d\n",ret);
}