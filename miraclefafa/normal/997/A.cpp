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
int n,cnt0;
ll x,y;
char s[N];
int main() {
	scanf("%d%lld%lld",&n,&x,&y);
	scanf("%s",s);
	rep(i,0,n) {
		if (s[i]=='0'&&(i==0||s[i-1]=='1')) cnt0++;
	}
	if (cnt0==0) {
		puts("0");
	} else {
		printf("%lld\n",(cnt0-1)*min(x,y)+y);
	}
}