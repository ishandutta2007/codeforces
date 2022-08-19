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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
char s[N];
ll cnt[40][40],cc[40],ans;
int main() {
	scanf("%s",s);
	int n=strlen(s);
	rep(i,0,n) {
		int w=s[i]-'a';
		rep(j,0,26) cnt[w][j]+=cc[j];
		cc[w]++;
	}
	rep(i,0,26) rep(j,0,26) ans=max(ans,cnt[i][j]);
	rep(i,0,26) ans=max(ans,cc[i]);
	printf("%lld\n",ans);
}