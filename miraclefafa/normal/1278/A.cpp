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

int _;
char p[110],q[110];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%s%s",p,q);
		int n=strlen(p),m=strlen(q);
		if (n>m) {
			puts("NO");
			continue;
		}
		bool suc=0;
		for (int i=0;i<=m-n;i++) {
			map<char,int> a,b;
			for (int j=0;j<n;j++) a[p[j]]++,b[q[j+i]]++;
			if (a==b) {
				suc=1;
				break;
			}
		}
		puts(suc?"YES":"NO");
	}
}