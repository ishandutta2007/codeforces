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

int n,q,ans,tran[10][10],dp[10][10];
char s[20],t[20];
int main() {
	scanf("%d%d",&n,&q);
	rep(i,0,q) {
		scanf("%s%s",s,t);
		tran[t[0]-'a'][s[0]-'a']++;
	}
	dp[0][0]=1;
	rep(i,0,n) {
		rep(j,0,6) rep(k,0,6) dp[i+1][k]+=dp[i][j]*tran[j][k];
	}
	rep(j,0,6) ans+=dp[n-1][j];
	printf("%d\n",ans);
}