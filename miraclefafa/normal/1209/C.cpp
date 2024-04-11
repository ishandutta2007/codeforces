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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int _,n,a[N],bit[N];
char s[N];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		scanf("%s",s);
		rep(i,0,n) a[i]=s[i]-'0';
		auto solve=[&]() {
			rep(md,0,10) {
				rep(i,0,n) {
					if (a[i]==md) bit[i]=3;
					else if (a[i]<md) bit[i]=1;
					else bit[i]=2;
				}
				bool v2=0;
				rep(i,0,n) {
					if (bit[i]==2) v2=1;
					if (bit[i]==3) { if (!v2) bit[i]=2; else bit[i]=1; }
				}
				VI v;
				rep(i,0,n) if (bit[i]==1) v.pb(a[i]);
				rep(i,0,n) if (bit[i]==2) v.pb(a[i]);
				bool f=1;
				rep(i,1,n) if (v[i]<v[i-1]) f=0;
				if (f) {
					rep(i,0,n) printf("%d",bit[i]);
					puts("");
					return 1;
				}
			}
			return 0;
		};
		if (!solve()) puts("-");
	}
}