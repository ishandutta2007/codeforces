#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

typedef pair<ll,ll> PLL;
const int N=301000;
PLL tmp[20],prec[N];
char S[N],*s=S;
VI getnum(char &token) {
	VI z; z.pb(token-'0');
	while (1) {
		token=*(s++);
		if (token>='0'&&token<='9') z.pb(token-'0');
		else { --s; return z; }
	}
}
PLL operator + (PLL a,PLL b) {
	return mp((a.fi*b.se+b.fi)%mod,(a.se*b.se)%mod);
}
PLL repeat(VI x,PLL r) {
	PLL c(0,1); tmp[0]=mp(0,1);
	rep(j,1,10) tmp[j]=tmp[j-1]+r;
	for (auto p:x) {
		PLL d(0,1); rep(j,0,10) d=d+c;
		c=d+tmp[p];
	}
	return c;
}
PLL trans(VI x) {
	ll s1=0,s2=1; for (auto p:x) s1=(s1*10+p)%mod,s2=s2*10%mod;
	return mp(s1,s2);
}

PLL fuckoff(ll p,ll s1,ll s2,ll s3) {
	if (s1<0) s1+=mod; if (s2<0) s2+=mod-1;
	ll v1=p*((s1*powmod(p,s2+1)-(s1+1)*powmod(p,s2)+1)%mod)%mod*powmod(p-1,mod-3)%mod;
	// sum (p^i*(b-i),)
	ll v2=(powmod(p,s2+1)-1)*powmod(p-1,mod-2)%mod*s3%mod;
	v2=(v2-v1)%mod; if (v2<0) v2+=mod;
	return mp(v2,powmod(p,s2+1));
}
PLL segment(VI a,VI b) {
	assert(SZ(a)==SZ(b));
	int l=SZ(a);
	ll p=powmod(10,l);
	ll s1=0,s2=0,s3=0;
	rep(i,0,l) s1=(s1*10+b[i]-a[i])%mod,s2=(s2*10+b[i]-a[i])%(mod-1),s3=(s3*10+b[i])%mod;
	return fuckoff(p,s1,s2,s3);
}
PLL concat(VI a,VI b) {
	if (SZ(a)==SZ(b)) return segment(a,b);
	else {
		PLL cr=segment(a,VI(SZ(a),9));
		rep(i,SZ(a)+1,SZ(b)) cr=cr+prec[i];
		VI c(1,1); rep(j,1,SZ(b)) c.pb(0);
		cr=cr+segment(c,b);
		return cr;
	}
}
PLL parse() {
	PLL cret(0,1);
	vector<int> num1;
	while (1) {
		char token=*(s++);
		if (token>='0'&&token<='9') {
			PLL cur(0,1);
			num1=getnum(token); token=*(s++);
			if (token=='(') {
				pair<ll,ll> r=parse();
//				printf("%lld %lld\n",r.fi,r.se);
				cur=repeat(num1,r);
//				printf("%lld %lld\n",cur.fi,cur.se);
				token=*(s++);
//				printf("s %c\n",token);
			} else if (token=='-') {
				token=*(s++);
				vector<int> num2=getnum(token);
				cur=concat(num1,num2);
				token=*(s++);
			} else if (token=='+'||token==')'||token==0) {
				cur=trans(num1);
			}
			cret=cret+cur;
			if (token!='+') return cret;
		}
	}
}
int main() {
	ll s1=9,s2=9,s3=10;
	rep(i,1,300001) prec[i]=fuckoff(s3,(s1-1),(s2-1),(s3-1)),s1=s1*10%mod,s2=s2*10%(mod-1),s3=s3*10%mod;
	scanf("%s",s);
	printf("%lld\n",parse().fi);
}