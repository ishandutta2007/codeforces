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

const int N=1001010;
int lc[N],rc[N],qc[N],n;
ll s1[N],s2[N],fac[N],fnv[N];
char s[N];
ll ans;
ll comb(int x,int y) {
	if (y<0||y>x) return 0;
	return fac[x]*fnv[y]%mod*fnv[x-y]%mod;
}
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n+1) {
		lc[i]=lc[i-1]+(s[i]=='(');
		rc[i]=rc[i-1]+(s[i]==')');
		qc[i]=qc[i-1]+(s[i]=='?');
	}
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	fnv[n]=powmod(fac[n],mod-2);
	per(i,1,n+1) fnv[i-1]=fnv[i]*i%mod;
	assert(fnv[0]==1);
	int p1=qc[n];
	for (int i=0;i<=p1;i++) s1[i]=comb(p1,i);
	for (int i=1;i<=p1;i++) s1[i]=(s1[i-1]+s1[i])%mod;
	if (p1>0) {
		int p2=qc[n]-1;
		for (int i=0;i<=p2;i++) s2[i]=comb(p2,i);
		for (int i=1;i<=p2;i++) s2[i]=(s2[i-1]+s2[i])%mod;
	}
	for (int pos=1;pos<=n;pos++) {
		if (s[pos]==')') continue;
		int f=qc[pos-1], g=qc[n]-qc[pos];
		int a=1+lc[pos-1],b=(rc[n]-rc[pos]);
		int w=min(g+b-a,f+g);
		if (w>=0) {
			if (f+g==qc[n]) ans+=s1[w];
			else ans+=s2[w];
		}
	}
	printf("%lld\n",ans%mod);
}