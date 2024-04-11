#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

#define int long long
int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2005;
int n,m,l[N],s[N],c[N<<1];
vector<int> dp[N<<1];
/*struct Hall {
	vector<int> v;
	void shrink() {
		vector<int> vv((v.size()-1>>1)+1);
		fo(i,0,v.size()) vv[i>>1]=max(vv[i>>1],v[i]);
		v=vv;
	}
	void sum() {fo(i,1,v.size()) v[i]=v[i-1]-v[i];}
	void dif() {rf(i,v.size()-1,1) v[i]=v[i-1]-v[i];}
} h[N],now;
Hall operator + (const Hall &a,const Hall &b) {
	int A=a.v.size()-1,B=b.v.size()-1;
	Hall c; c.v.resize(A+B+1);
	c.v[0]=a.v[0]+b.v[0]; int cur=0;
	for(int l=0,r=0;l<=A&&r<=B;) {
		if(r==B||(l<A&&a.v[l+1]-a.v[l]>=b.v[r+1]-a.v[r]))
			c.v[++cur]=a.v[++l]+b.v[r];
		else c.v[++cur]=a.v[l]+b.v[++r];
	} return c;
}*/
int calc(int i,int cnt) {
	int ans=0;
	while(cnt>>=1) ans+=c[++i]*cnt;
	return ans;
}
signed main() {
	n=read(),m=read();
	fr(i,1,n) l[i]=read();
	fr(i,1,n) s[i]=read();
	fr(i,1,n+m) c[i]=read();
	int ans=0;
	fr(i,1,n+m) dp[i].resize(1);
	rf(i,n,1) {
		vector<int> &v=dp[l[i]];
		v.push_back((ll)(-4e18));
		rf(j,v.size()-1,1) v[j]=max(v[j],v[j-1]+c[l[i]]-s[i]);
		fo(j,l[i],n+m) {
			if(dp[j+1].size()<(dp[j].size()-1>>1)+1) dp[j+1].push_back((ll)(-4e18));
			fo(k,0,dp[j].size()) dp[j+1][k>>1]=max(dp[j+1][k>>1],dp[j][k]+(k>>1)*c[j+1]);
		}
	}
	fr(i,1,n+m) fo(j,0,dp[i].size()) ans=max(ans,dp[i][j]+calc(i,j));
	printf("%lld\n",ans);
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}