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

const int inf=0x20202020;
unsigned short dp[42000000];
int qq[42000000];

int p[2010],q[2010],n,t,ans=1e9;

void upd(int cur,int el,int p1,int p2,int p3,int p4,int v) {
	VI g; int pur=cur;
	if (p1&&p1!=el) g.pb(p1);
	if (p2&&p2!=el) g.pb(p2);
	if (p3&&p3!=el) g.pb(p3);
	if (p4&&p4!=el) g.pb(p4);
	for (auto p:g) assert(p!=el);
	p1=0; p2=0; p3=0; p4=0;
	for (int c=cur;SZ(g)<4&&c<=n;c++) if (p[c]==el) {
		g.pb(q[c]); pur=c+1;
	} else break;
	if (!g.empty()&&g.back()==q[pur-1]) {
		p4=1;
		g.pop_back();
	}
	if (!g.empty()) {
		p3=g.back();
		g.pop_back();
	}
	if (!g.empty()) {
		p2=g.back();
		g.pop_back();
	}
	if (!g.empty()) {
		p1=g.back();
		g.pop_back();
	}
	assert(g.empty());
	int id=pur*20000+el*2000+p1*200+p2*20+p3*2+p4;
	if (v<dp[id]) dp[id]=v,qq[t++]=id;
	if (pur==n+1&&p1==0&&p2==0&&p3==0&&p4==0) ans=min(ans,v);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d%d",p+i,q+i);

	memset(dp,0xff,sizeof(dp));
	upd(1,1,0,0,0,0,0);
	rep(h,0,t) {
		int c=qq[h];
		int i=c/20000,el=c/2000%10,p1=c/200%10,p2=c/20%10,p3=c/2%10,q4=c%2,p4=0;
		if (q4!=0) p4=q[i-1];
		int v=dp[c];
//		printf("%d %d %d %d %d %d %d\n",i,el,p1,p2,p3,p4,v);
		if (el+1<=9) upd(i,el+1,p1,p2,p3,p4,v+1);
		if (el-1>=1) upd(i,el-1,p1,p2,p3,p4,v+1);
	}
	printf("%d\n",ans+2*n);
}