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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int _,p[N],n;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		for (int i=1;i<=2*n;i++) scanf("%d",p+i);
		map<int,int> hs;
		int bal=0;
		hs[0]=0;
		for (int i=1;i<=n;i++) {
			if (p[i]==1) bal++; else bal--;
			hs[bal]=i;
		}
		int ans=0;
		bal=0;
		for (int i=2*n;i>=n;i--) {
			if (hs.count(bal)) {
				ans=max(ans,2*n-i+hs[bal]);
			}
			if (p[i]==1) bal--; else bal++;
		}
		printf("%d\n",2*n-ans);
	}
}