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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
string s;
map<ll,int> hs;
int c=1;
ll bit[100];
int main() {
	cin>>s;

	while (!s.empty()&&s[0]=='0') s.erase(s.begin()),++c;
	if (s.empty()) {
		puts("-1");
		return 0;
	}
	while (s.back()=='0') s.pop_back();
	int m=SZ(s);
	ll num=0;
	rep(i,0,m) num|=(s[i]-'0')*(1ll<<i);
	int T=600000;
	ll p=1;
	for (int i=0;i<T;i++) {
		hs[p]=i;
		if (i<80) bit[i]=p;
		p=(p<<1);
		if (p&(1ll<<(m-1))) p^=num;
	}
	int T2=60000;
	ll q=1;
	for (int i=1;i<=T2;i++) {
		ll tmp=0;
		rep(j,0,m) if (q&(1ll<<j))
			rep(k,0,m) if (p&(1ll<<k)) 
				tmp^=bit[j+k];
		q=tmp;
		if (hs.count(q)) {
			printf("%d %lld\n",c,c+1ll*i*T-hs[q]);
			return 0;
		}
	}
	puts("-1");
}