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

ll fib[60],k;
int n,perm[60];
void dfs(int p,ll c) {
	assert(c<fib[n-p]);
	if (p==n) {
		assert(c==0);
		rep(i,0,n) printf("%d ",perm[i]+1);
		exit(0);
	} else {
		if (c<fib[n-1-p]) {
			perm[p]=p;
			dfs(p+1,c);
		} else {
			perm[p]=p+1;
			perm[p+1]=p;
			dfs(p+2,c-fib[n-1-p]);
		}
	}
}
int main() {
	fib[0]=1;
	fib[1]=1;
	rep(i,2,51) fib[i]=fib[i-1]+fib[i-2];
	scanf("%d%I64d",&n,&k); --k;
	dfs(0,k);
}