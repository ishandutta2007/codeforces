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

const int N=301000;
int n,s1,s2;
PII p[N];
VI v1,v2;
bool solve(int ty=0) {
	int k2=-1;
	rep(i,0,n) if ((ll)p[i].fi*(i+1)>=s2) {
		k2=i+1;
		v2.clear();
		rep(j,0,i+1) v2.pb(p[j].se);
		break;
	}
	if (k2==-1) return 0;
	int k1=-1;
	rep(i,k2,n) if ((ll)p[i].fi*(i-k2+1)>=s1) {
		k1=i-k2+1;
		v1.clear();
		rep(j,k2,i+1) v1.pb(p[j].se);
		break;
	}
	if (k1==-1) return 0;
	if (ty==1) swap(v1,v2);
	puts("Yes");
	printf("%d %d\n",SZ(v1),SZ(v2));
	for (auto p:v1) printf("%d ",p+1); puts("");
	for (auto p:v2) printf("%d ",p+1); puts("");
	return 1;
}
int main() {
	scanf("%d%d%d",&n,&s1,&s2);
	rep(i,0,n) scanf("%d",&p[i].fi),p[i].se=i;
	sort(p,p+n);
	reverse(p,p+n);
	if (solve()) return 0;
	swap(s1,s2);
	if (solve(1)) return 0;
	puts("No");
}