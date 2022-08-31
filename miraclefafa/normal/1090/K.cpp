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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010000;
int n,tot;
char s[N],t[N];
map<pair<string,int>,int> hs;
VI lst[N];

int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%s%s",s,t);
		int p2=strlen(s);
		int p1=strlen(t);
		int st=0;
		rep(i,0,p1) st|=1<<(t[i]-'a');
		int lp=0;
		rep(i,0,p2) {
			if (st&(1<<(s[i]-'a'))) {
			} else {
				lp=i+1;
			}
		}
		string key(s,s+lp);
		if (!hs.count(mp(key,st))) {
			hs[mp(key,st)]=tot;
			tot++;
		}
		lst[hs[mp(key,st)]].pb(i+1);
	}
	printf("%d\n",tot);
	rep(i,0,tot) {
		printf("%d",SZ(lst[i]));
		for (auto p:lst[i]) printf(" %d",p);
		puts("");
	}
}