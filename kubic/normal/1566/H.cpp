#include <bits/stdc++.h>
using namespace std;
#define N 505
#define M 1000005
#define M1 50005
#define C 105
#define LIM 1000005
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
#define gc getchar
mt19937 rand1(998244353);
char *P1,*P2,buf[LIM];
int n,m,cnt,vs[M],p[M],w[M],z[M],ord[M];
int tp,tp1,tp2,tpZ,st[N],st1[N],st2[N],vl[C],vl1[C],z2[N],z1[N][C][C];
bool tg[M],ans[M];vector<int> vc[M];bitset<M1> dp[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
void print(int x) {if(x<10) {putchar(x+48);return;}print(x/10);putchar(x%10+48);}
bool cmp(int x,int y) {return vc[x].size()>vc[y].size();}
void sieve(int n)
{
	vs[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) vs[i]=p[++p[0]]=i;
		for(int j=1;i*p[j]<=n;++j) {vs[i*p[j]]=p[j];if(!(i%p[j])) break;}
	}
}
int main()
{
	m=rd();n=rd();sieve(m);
	for(int i=1,lst=0;i<=m;++i,lst=0)
	{w[i]=1;for(int j=i;j>1;j/=vs[j]) if(vs[j]!=lst) w[i]*=vs[j],lst=vs[j];}
	for(int i=1;i<=m;++i) if(w[i]==i) ord[cnt++]=i;print(cnt);putchar(' ');
	for(int i=1;i<=m;++i) if(w[i]==i) print(i),putchar(' ');fflush(stdout);
	for(int i=1;i<=m;++i) if(w[i]==i)
	{z[i]^=rd();for(int j=i*2;j<=m;j+=i) if(w[j]==j) z[j]^=z[i];}
	for(int i=m;i;--i) if(w[i]==i) for(int j=i*2;j<=m;j+=i) if(w[j]==j) z[i]^=z[j];
	for(int i=1;i<=m;++i) vc[w[i]].pb(i);sort(ord,ord+cnt,cmp);
	for(int i=0;i<min(cnt,500);++i) tg[ord[i]]=1;
	for(int i=1,t,t1,nw,up;i<=m;++i) if(w[i]==i)
	{
		tp=tp1=0;for(int j=0;j<20;++j) vl[j]=0;
		for(auto j:vc[i])
		{
			t=j;t1=1<<tp;
			for(int k=19;k>=0;--k) if(t>>k&1)
			{if(!vl[k]) {st[tp++]=j;vl[k]=t;vl1[k]=t1;break;}t^=vl[k];t1^=vl1[k];}
			if(!t) st1[tp1++]=j;
		}
		if(!tg[i])
		{
			t=z[i];t1=0;for(int j=19;j>=0;--j) if(t>>j&1) t^=vl[j],t1^=vl1[j];
			for(int j=0;j<tp;++j) if(t1>>j&1) ans[st[j]]=1,--n;continue;
		}z2[++tpZ]=i;
		for(int tim=0;tim<100;++tim)
		{
			nw=0;up=rand1()%(min(tp1+1,100-tp));tp2=0;t=z[i];t1=0;
			for(int j=0;j<tp1;++j)
				if(nw<up && rand1()%tp1<up) st2[tp2++]=st1[j],t^=st1[j];
			for(int j=19;j>=0;--j) if(t>>j&1) t^=vl[j],t1^=vl1[j];
			for(int j=0;j<tp;++j) if(t1>>j&1) st2[tp2++]=st[j];
			if(!z1[tpZ][tp2][0]) for(int j=0;j<tp2;++j) z1[tpZ][tp2][j]=st2[j];
		}
	}dp[0][0]=1;
	for(int i=1;i<=tpZ;++i)
	{
		if(!z[z2[i]]) dp[i]=dp[i-1];
		for(int j=1;j<100;++j) if(z1[i][j][0]) dp[i]|=dp[i-1]<<j;
	}
	for(int i=tpZ;i;--i)
	{
		if(dp[i-1][n] && !z[z2[i]]) continue;
		for(int j=1;j<min(n+1,100);++j) if(dp[i-1][n-j] && z1[i][j][0])
		{for(int k=0;k<j;++k) ans[z1[i][j][k]]=1;n-=j;break;}
	}for(int i=1;i<=m;++i) if(ans[i]) print(i),putchar(' ');return 0;
}