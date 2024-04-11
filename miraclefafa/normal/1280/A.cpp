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

const int N=2010000;
int x,_;
char s[N];
void solve() {
    scanf("%d",&x);
    scanf("%s",s);
    int l=strlen(s);
    ll tl=l;
    for (int i=0;i<x;i++) {
    	int p=s[i]-'1';
    	if (l<x) {
	    	int pl=i+1,pr=l;
	    	for (int j=0;j<p;j++) {
	    		for (int k=pl;k<pr;k++) {
	    			if (l>=x) break;
	    			s[l++]=s[k];
	    		}
	    	}
		}
		s[l]=0;
		tl=(tl+(tl-i-1)*p)%mod;
		//printf("%d %lld %s\n",i,tl,s);
    }
    if (tl<0) tl+=mod;
    printf("%lld\n",tl);
}

int main() {
    for (scanf("%d",&_);_;_--) {
        solve();
    }
}