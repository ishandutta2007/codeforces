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

const int N=1010;
int n,k1,k2;
int a[N],b[N];
ll ret;

int main() {
	scanf("%d%d%d",&n,&k1,&k2);
	k1+=k2;
	rep(i,0,n) scanf("%d",a+i);
	rep(i,0,n) scanf("%d",b+i),a[i]-=b[i];
	rep(v,0,k1) {
		int val=-1,pos=-1;
		rep(i,0,n) if (abs(a[i])>val) {
			val=abs(a[i]); pos=i;
		}
		if (a[pos]>0) a[pos]--; else a[pos]++;
	}
	rep(i,0,n) ret+=(ll)a[i]*a[i];
	printf("%lld\n",ret);
}