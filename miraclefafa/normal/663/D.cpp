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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=5010;
int n,mt[N][3],sco[N][3],sol[10],hc[10],sv[N][30];
int dp[110][110][110];
VI hs[N];
int ff(int n,int p,int id) {
	int v=(n>>(p+1))+1; //
	if (p==5) v=0;
//	printf("%d %d %d %d %d\n",n,p,id,sol[id],hc[id]);
	if ((v<<p)>n) return -1;
	if (v>sol[id]) return -1;
	if (((sol[id]-hc[id])<<p)>n) return -1;
	return min(sol[id]-v,hc[id]);
}
int gg(int mt,int p) {
	if (mt==0) return 0;
	if (mt<0) mt*=-1;
	return (p+1)*2*(250-mt);
}
inline void upd(int &a,int b) {
	if (a>b) a=b;
}
int main() {
	scanf("%d",&n);
	int tot=0;
	rep(i,0,n) {
		rep(j,0,3) {
			scanf("%d",&mt[i][j]);
			if (mt[i][j]!=0) sol[j]++;
			if (mt[i][j]<0) tot++,hc[j]++;
		}
		rep(S,0,8) if ((mt[i][0]<0||(S&1)==0)&&(mt[i][1]<0||(S&2)==0)&&(mt[i][2]<0||(S&4)==0))
			hs[i].pb(S);
	}
	if (tot>90) {
		puts("1");
		return 0;
	}
	int ans=n;
	rep(p1,0,6) rep(p2,0,6) rep(p3,0,6) {
		int h1=ff(n,p1,0),h2=ff(n,p2,1),h3=ff(n,p3,2);
		if (h1<0||h2<0||h3<0) continue;
		rep(i,0,n) {
			sco[i][0]=gg(mt[i][0],p1);
			sco[i][1]=gg(mt[i][1],p2);
			sco[i][2]=gg(mt[i][2],p3);
//			printf("%d %d %d\n",sco[i][0],sco[i][1],sco[i][2]);
			for (auto S:hs[i]) {
				int sc=0;
				rep(j,0,3) if ((S&(1<<j))==0) sc+=sco[i][j];
				sv[i][S]=sc;
			}
		}
		int ss=sco[0][0]+sco[0][1]+sco[0][2]+100*(h1+h2+h3);
		int pre=1;
		memset(dp,0x20,sizeof(dp));
		dp[0][0][0]=0;
		int l1=0,l2=0,l3=0;
		rep(i,1,n) {
			if (mt[i][0]>=0&&mt[i][1]>=0&&mt[i][2]>=0) {
				pre+=(sco[i][0]+sco[i][1]+sco[i][2])>ss;
				continue;
			}
			per(v1,0,l1+1) per(v2,0,l2+1) per(v3,0,l3+1) {
				for (auto S:hs[i]) upd(dp[v1+((S>>0)&1)][v2+((S>>1)&1)][v3+((S>>2)&1)],dp[v1][v2][v3]+(sv[i][S]>ss));
				dp[v1][v2][v3]+=(sv[i][0]>ss);
			}
			l1=min(h1,l1+(mt[i][0]<0));
			l2=min(h2,l2+(mt[i][1]<0));
			l3=min(h3,l3+(mt[i][2]<0));
		}
		ans=min(ans,pre+dp[h1][h2][h3]);
//		printf("%d %d %d %d %d %d %d\n",p1,p2,p3,h1,h2,h3,pre+dp[h1][h2][h3]);
	}
	printf("%d\n",ans);
}