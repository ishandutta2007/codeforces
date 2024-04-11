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

typedef unsigned long long ull;

const int N=(1<<14)+10;
int cc[20],c[20],diff[20],k,car,T,dig[N][15],cnt[N],sm[N];
ll dp[N][15];
int mt[N][15];
char s[20];
ll ret=(1ll<<60);
void gao() {
	rep(i,0,k) {
		ll v=c[i]+(i==0?0:cc[i-1]);
		diff[i]=(cc[i]==0?v:v-16);
		if (diff[i]==16) return;
	}
	T++;
	dp[(1<<(k-1))][k-1]=0; mt[(1<<(k-1))][k-1]=T;
	int aS=(1<<k)-1;
	rep(i,(1<<(k-1)),aS+1) {
		sm[i]=sm[i^(1<<dig[i][0])]+diff[dig[i][0]];
		rep(w,0,cnt[i]) {
			int j=dig[i][w];
			if (mt[i][j]!=T) continue;
			int v=(sm[i]-diff[j])&15,nv=v+diff[j];
			if (nv<0||nv>=16) continue;
			if (i==aS) ret=min(ret,dp[aS][j]);
			int nS=aS^i;
			ll ww=dp[i][j];
			rep(w2,0,cnt[nS]) {
				int j2=dig[nS][w2];
				int S=i^(1<<j2);
				if (mt[S][j2]!=T) mt[S][j2]=T,dp[S][j2]=(1ll<<60);
				ll ww2=ww+(((ll)nv)<<(4*j2));
				if (ww2<dp[S][j2]) dp[S][j2]=ww2;
			}
		}
	}
}
void dfs(int u,int car) {
	if (u==k-1) {
		if (car%16!=0) {
			return;
		}
		gao();
	} else {
		cc[u]=0;
		dfs(u+1,car);
		cc[u]=1;
		dfs(u+1,car+1);
	}
}
int main() {
	scanf("%s",s);
	k=strlen(s);
	rep(i,0,k) c[i]=(s[i]>='a'?s[i]-'a'+10:s[i]-'0');
	reverse(c,c+k);
	rep(i,0,k) car+=c[i];
	rep(i,0,(1<<k)) {
		cnt[i]=0;
		rep(j,0,k) if (i&(1<<j)) dig[i][cnt[i]++]=j;
	}
	ret=(1ll<<60);
	dfs(0,car);
	if (ret==(1ll<<60)) puts("NO");
	else {
		per(i,0,k) {
			ll w=(ret>>(i*4))&15;
			if (w<10) putchar(w+'0'); else putchar(w-10+'a');
		}
		puts("");
	}
}