//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,K,mx[1005],my[1005],s[1005],v[1005],p[1005][1005],q[1005][1005];
int st[1005],tp,ax[1005],ay[1005],lp[1005][1005],res;long double at[1005][1005];
inline char chk(int i,int a,int b)
{
	int sx=mx[a]-ax[i],sy=my[a]-ay[i],tx=mx[b]-ax[i],ty=my[b]-ay[i];
	return 1ll*sx*ty==1ll*sy*tx&&1ll*sx*tx+1ll*sy*ty>0;
}
inline ll getd(int i,int a)
{
	int x=mx[a]-ax[i],y=my[a]-ay[i];
	return 1ll*x*x+1ll*y*y;
}
inline int check(int i,int tt)
{
	int j,wh,hw,nw;if(!tt) return -1;else j=s[tt-1],wh=q[j][i],hw=lp[j][wh],nw=tt-1;
	for(int k=hw;k<wh;k++) if(!v[p[j][k]]) if((nw=check(p[j][k],nw))==-1) return -1;
	return v[i]=1,st[++tp]=i,nw;
}
int main()
{
	read(K),read(n);for(int i=0;i<K;i++) read(ax[i]),read(ay[i]);
	for(int i=1;i<=n;i++) read(mx[i]),read(my[i]);
	for(int i=0;i<K;i++)
	{
		for(int j=1;j<=n;j++) at[i][j]=atan2l(my[j]-ay[i],mx[j]-ax[i]);
		for(int j=1;j<=n;j++) p[i][j]=j;
		sort(p[i]+1,p[i]+n+1,[=](int a,int b){return chk(i,a,b)?getd(i,a)<getd(i,b):at[i][a]<at[i][b];});
		for(int j=1;j<=n;j++) lp[i][j]=j==1?1:chk(i,p[i][j-1],p[i][j])?lp[i][j-1]:j;
		for(int j=1;j<=n;j++) q[i][p[i][j]]=j;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<K;j++) s[j]=j;
		do
		{
			int rs=check(i,K);while(tp) v[st[tp--]]=0;
			if(~rs) {++res;break;}
		}while(next_permutation(s,s+K));
	}
	return printf("%d\n",res),0;
}