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

const int N=110;
int n,deg[N];
char s[N][N];
VI ret;
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%s",s[i]);
	rep(i,0,n) scanf("%d",deg+i);
	while (1) {
		int pv=-1;
		rep(i,0,n) if (deg[i]==0) pv=i;
		if (pv==-1) break;
		ret.pb(pv);
		rep(i,0,n) if (s[pv][i]=='1') deg[i]--;
	}
	printf("%d\n",SZ(ret));
	for (auto p:ret) printf("%d ",p+1);
}