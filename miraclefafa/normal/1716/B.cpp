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

int _,n,a[110];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,1,n+1) a[i]=i;
		printf("%d\n",n);
		rep(i,1,n+1) printf("%d%c",a[i]," \n"[i==n]);
		rep(j,2,n+1) {
			swap(a[1],a[j]);
			rep(i,1,n+1) printf("%d%c",a[i]," \n"[i==n]);
		}
	}
}