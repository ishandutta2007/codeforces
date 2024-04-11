//{{{
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf,buffer[1<<21];int P1=-1;const int P2=(1<<21)-1;
inline void flush() {fwrite(buffer,1,P1+1,stdout),P1=-1;}
inline void putc(const char &x) {if(P1==P2) flush();buffer[++P1]=x;}
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar();for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
}
template<typename T>inline void write(T x)
{
	int y=10,len=1;while(y<=x) y*=10,len++;
	while(len--) y/=10,putc(x/y+48),x%=y;
}/*}}}*/
int q,tot,fa[500005];double F[500005][65];
int main()
{
	read(q),tot=1;for(int i=1;i<=63;i++) F[1][i]=1;
	for(int op,x;q--;)
	{
		read(op),read(x);
		if(op==2)
		{
			double res=62;for(int i=1;i<63;i++) res-=F[x][i];
			printf("%.10lf\n",res);continue;
		}
		vector<int>v;fa[++tot]=x,x=tot;
		for(int i=1;i<=63;i++) F[x][i]=1;
		for(int i=1;i<=64&&x;i++) v.push_back(x),x=fa[x];
		for(int i=v.size()-2;i;i--) F[v[i+1]][i+1]/=(F[v[i]][i]+1)/2;
		for(int i=0;i+1<(int)v.size();i++) F[v[i+1]][i+1]*=(F[v[i]][i]+1)/2;
	}
	return 0;
}