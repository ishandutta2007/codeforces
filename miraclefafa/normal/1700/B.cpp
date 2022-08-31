#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int _;
char s[N];
int a[N];
int main() {
	for (scanf("%d",&_);_;_--) {
		int n;
		scanf("%d",&n);
		scanf("%s",s);
		if (s[0]!='9') {
			rep(i,0,n) printf("%d",9-(s[i]-'0'));
			puts("");
		} else {
			rep(i,0,n) {
				a[i]=10-(s[i]-'0');
			}
			a[n-1]+=1;
			per(i,1,n) {
				a[i-1]+=a[i]/10;
				a[i]%=10;
			}
			rep(i,0,n) printf("%d",a[i]); puts("");
		}
	}
}