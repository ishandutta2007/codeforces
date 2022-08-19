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

set<int> cs,cb;
VI cand;
int n,p,ms,mb;
char s[1010];
ll ans=1;
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%s%d",s,&p);
		if (!cs.empty()) ms=*(--cs.end()); else ms=-1;
		if (!cb.empty()) mb=*(cb.begin()); else mb=1<<30;
		if (s[1]=='D') {
			if (p>ms&&p<mb) {
				cand.pb(p);
			} else {
				if (p<=ms) cs.insert(p);
				if (p>=mb) cb.insert(p);
			}
		} else { // accept
			if (p<ms||p>mb) {
				puts("0");
				return 0;
			}
			if (p==ms) {
				cs.erase(p);
				for (auto x:cand) cb.insert(x);
				cand.clear();
				continue;
			}
			if (p==mb) {
				cb.erase(p);
				for (auto x:cand) cs.insert(x);
				cand.clear();
				continue;
			}
			bool fd=0;
			for (auto x:cand) {
				if (x==p) {
					fd=1;
				} else {
					if (x<p) cs.insert(x);
					else cb.insert(x);
				}
			}
			assert(fd);
			cand.clear();
			ans=ans*2%mod;
		}
	}
	ans=ans*(SZ(cand)+1)%mod;
	printf("%lld\n",ans);
}