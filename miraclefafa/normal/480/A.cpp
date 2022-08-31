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

const int N=101000;
PII p[N];
int n;
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d%d",&p[i].fi,&p[i].se);
	sort(p,p+n);
	int ret=p[0].se;
	rep(i,1,n) {
		if (ret<=p[i].se) ret=p[i].se;
		else ret=p[i].fi;
	}
	printf("%d\n",ret);
}