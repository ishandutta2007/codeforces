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

typedef long double LD;
int a,b,c,d;
void gao(LD a,LD d,LD x,LD &pl,LD &pr) {
	pr=max(max((a+x)*(d+x),(a-x)*(d+x)),max((a+x)*(d-x),(a-x)*(d-x)));
	pl=min(min((a+x)*(d+x),(a-x)*(d+x)),min((a+x)*(d-x),(a-x)*(d-x)));
}
bool check(LD x) {
	LD pl,pr,ql,qr;
	gao(a,d,x,pl,pr);
	gao(b,c,x,ql,qr);
	if (qr<pl||pr<ql) return 0; else return 1;
}
int main() {
	scanf("%d%d%d%d",&a,&b,&c,&d);
	LD l=0,r=2e9;
	rep(i,0,200) {
		LD md=(l+r)*0.5;
		if (check(md)) r=md; else l=md;
	}
	printf("%.10f\n",(double)((l+r)*0.5));
}