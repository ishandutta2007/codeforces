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

int _,a,b;
bool solve() {
	VI da,db;
	rep(i,0,30) if (a&(1<<i)) da.pb(i);
	rep(i,0,30) if (b&(1<<i)) db.pb(i);	
	if (a>b) return 0;
	if (SZ(da)<SZ(db)) return 0;
	rep(i,0,SZ(db)) if (da[i]>db[i]) return 0;
	return 1;
}

int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&a,&b);
		puts(solve()?"YES":"NO");
	}

}