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

int n,q,r,c,f[3][101000],ans;
int main() {
	scanf("%d%d",&n,&q);
	rep(i,0,q) {
		scanf("%d%d",&r,&c);
		f[r][c]^=1;
		if (f[r][c]) {
			rep(j,-1,2) if (f[3-r][c+j]) ans++;
		} else {
			rep(j,-1,2) if (f[3-r][c+j]) ans--;			
		}
		puts(ans?"No":"Yes");
	}
}