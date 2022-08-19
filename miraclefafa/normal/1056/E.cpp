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

const int N=1010000;

int n,m;
char s[N],t[N];
hashv pw[N],hv[N];

int main() {
	hashv base(13331,23333);
	pw[0]=hashv(1,1);
	scanf("%s",s);
	scanf("%s",t);
	n=strlen(s);
	m=strlen(t);
	rep(i,1,m+1) pw[i]=pw[i-1]*base;
	rep(i,1,m+1) hv[i]=hv[i-1]*base+hashv(t[i-1],t[i-1]);
	int c0=0,c1=0,ans=0;
	for (int i=0;i<n;i++) if (s[i]=='0') c0++; else c1++;
	for (int l0=1;l0*c0<m;l0++) {
		int l1=-1;
		if ((m-l0*c0)%c1==0) {
			l1=(m-l0*c0)/c1;
		} else {
			continue;
		}
		bool f0=0,f1=0;
		hashv s0,s1;
		int len=0;
		bool suc=1;
		rep(i,0,n) {
			if (s[i]=='0') {
				if (!f0) {
					s0=hv[len+l0]-hv[len]*pw[l0];
					f0=1;
				} else {
					hashv tmp=hv[len+l0]-hv[len]*pw[l0];
					if (tmp!=s0) {
						suc=0;
						break;
					}
				}
				len+=l0;
			} else {
				if (!f1) {
					s1=hv[len+l1]-hv[len]*pw[l1];
					f1=1;
				} else {
					hashv tmp=hv[len+l1]-hv[len]*pw[l1];
					if (tmp!=s1) {
						suc=0;
						break;
					}
				}
				len+=l1;
			}
		}
//		printf("%d %d %d %d %d %d\n",l0,l1,s0.fi,s0.se,s1.fi,s1.se);
		if (suc&&s0!=s1) {
			ans++;
		}
	}
	printf("%d\n",ans);
}