//{{{
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
//int debug[105][105];
inline char qry1(int x,int y)
{
	printf("1 %d %d\n",x,y),fflush(stdout);//return debug[x][y];
	char w;return read(w),w;
}
inline char qry2(int x,vector<int>v)
{
	printf("2 %d %d ",x,(int)v.size());for(auto y:v) printf("%d ",y);
	//putchar('\n'),fflush(stdout);int r=0;for(auto y:v) r|=debug[x][y];return r;
	char w;return putchar('\n'),fflush(stdout),read(w),w;
}
mt19937 getrand(114514);int Ca,n,ls[105];char rs[105][105];
inline vector<int>srt(const vector<int>&v)
{
	int bas;if((int)v.size()<2) return v;else bas=getrand()%v.size();
	vector<int>l,r,rs;for(int i=0;i<(int)v.size();i++) if(i^bas) (qry1(v[i],v[bas])?l:r).push_back(v[i]);
	l=srt(l),r=srt(r);for(auto x:l) rs.push_back(x);rs.push_back(v[bas]);for(auto x:r) rs.push_back(x);
	return rs;
}
inline void solve()
{
	read(n);vector<int>v(n);for(int i=0;i<n;i++) v[i]=i,ls[i]=0;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) rs[i][j]=0;
	//for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%1d",&debug[i][j]);
	v=srt(v);for(int i=0;i<n;i++) for(int j=i;j<n;j++) rs[v[i]][v[j]]=1;
	int nw=n-2;for(int i=n-1;~i;i--) for(nw-=nw==i;;)
	{
		if(nw<0) {ls[i]=0;break;}
		vector<int>q;for(int j=0;j<=nw;j++) q.push_back(v[j]);
		if(qry2(v[i],q)) nw--;else {ls[i]=nw+1;break;}
	}
	for(int i=0;i<n;i++) for(int j=ls[i];j<=i;j++) ls[i]=min(ls[i],ls[j]);
	for(int i=0;i<n;i++) for(int j=ls[i];j<=i;j++) rs[v[i]][v[j]]=1;
	puts("3");for(int i=0;i<n;i++,putchar('\n')) for(int j=0;j<n;j++) printf("%d",rs[i][j]);
	fflush(stdout);int FUCK;read(FUCK);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}