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

int _,n,k;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&k);
		if (k!=n-1) {
			printf("%d %d\n",0,n-1-k);
			if (k!=0) printf("%d %d\n",k,n-1);
			rep(i,0,n/2) if (i!=0&&i!=k&&i!=n-1-k) {
				printf("%d %d\n",i,n-1-i);
			}
		} else {
			if (n==4) puts("-1"); else {
				printf("%d %d\n",0,n/2);
				printf("%d %d\n",n/2-1,n-1);
				printf("%d %d\n",1,n/2-2);
				printf("%d %d\n",n-2,n/2+1);
				rep(i,2,n/2-2) {
					printf("%d %d\n",i,n-1-i);
				}
			}
		}
	}
}