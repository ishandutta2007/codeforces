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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

#define prev prerere
const int N=2010000;
int n,m,k,dp[N],prev[30];
char t[N];
int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",t); m=strlen(t);
	rep(i,0,k) prev[i]=0;
	dp[0]=1;
	rep(i,1,m+1) {
		int w=t[i-1]-'a';
		if (prev[w]) dp[i]=(2*dp[i-1]-dp[prev[w]-1])%mod;
		else dp[i]=2*dp[i-1]%mod;
		if (dp[i]<0) dp[i]+=mod;
		prev[w]=i;
	}
	rep(i,m+1,n+m+1) {
		int w=min_element(prev,prev+k)-prev;
		if (prev[w]) dp[i]=(2*dp[i-1]-dp[prev[w]-1])%mod;
		else dp[i]=2*dp[i-1]%mod;
		if (dp[i]<0) dp[i]+=mod;
		prev[w]=i;
	}
	printf("%d\n",dp[n+m]);
}