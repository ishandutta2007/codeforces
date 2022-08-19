#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int w,h,n,d;
char s[10];
set<int> sh,sw;
multiset<int> ph,pw;
int main() {
	scanf("%d%d%d",&w,&h,&n);
	sh.insert(0); sh.insert(h);
	ph.insert(h);
	sw.insert(0); sw.insert(w);
	pw.insert(w);
	rep(i,0,n) {
		scanf("%s%d",s,&d);
		if (s[0]=='H') {
			auto it=sh.lower_bound(d);
			auto pit=it; --pit;
			ph.erase(ph.lower_bound(*it-*pit));
			sh.insert(d);
			ph.insert(*it-d); ph.insert(d-*pit);
		} else {
			auto it=sw.lower_bound(d);
			auto pit=it; --pit;
			pw.erase(pw.lower_bound(*it-*pit));
			sw.insert(d);
			pw.insert(*it-d); pw.insert(d-*pit);
		}
		printf("%I64d\n",1ll*(*ph.rbegin())*(*pw.rbegin()));
	}
}