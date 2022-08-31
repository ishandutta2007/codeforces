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

int _;

typedef pair<int,int> hashv;
const ll mod1=1000000007;
const ll mod2=1000000009;

hashv operator + (hashv a,hashv b) {
	int c1=a.fi+b.fi,c2=a.se+b.se;
	if (c1>=mod1) c1-=mod1;
	if (c2>=mod2) c2-=mod2;
	return mp(c1,c2);
}

hashv operator - (hashv a,hashv b) {
	int c1=a.fi-b.fi,c2=a.se-b.se;
	if (c1<0) c1+=mod1;
	if (c2<0) c2+=mod2;
	return mp(c1,c2);
}

hashv operator * (hashv a,hashv b) {
	return mp(1ll*a.fi*b.fi%mod1,1ll*a.se*b.se%mod2);
}

const int N=501000;
int n;
char s[N];
hashv pw[N],base;
void solve() {
	scanf("%d",&n);
	scanf("%s",s);
	int l=0,cnt=0;
	while (l+1<n) {
		if (s[l]=='(') l+=2,cnt++;
		else {
			hashv vl=hashv(s[l],s[l]),vr=hashv(s[l],s[l]);
			bool fd=0;
			rep(r,l+1,n) {
				vl=vl*base+hashv(s[r],s[r]);
				vr=vr+hashv(s[r],s[r])*pw[r-l];
				if (vl==vr) {
					l=r+1;
					cnt++;
					fd=1;
					break;
				}
			}
			if (!fd) break;
		}
	}
	printf("%d %d\n",cnt,n-l);
}

int main() {
	base=hashv(rnd(mod1),rnd(mod2));
	pw[0]=mp(1,1);
	rep(i,1,500001) pw[i]=pw[i-1]*base;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}