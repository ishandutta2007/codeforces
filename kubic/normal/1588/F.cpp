//???
#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define M 405
#define M1 1505
#define LIM 1000005
#define ll long long
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const int B=400;char *P1,*P2,buf[LIM];
int n,m,m1,vs[N],p[N],p1[N],rv[N],id[N],tg[N],z[M][M1];ll s[N],nw[M1],vl1[N],vl2[N];
struct Query {int F[3];}a[M];struct Node {int x,w;};vector<Node> vc[N];
int rd()
{
	int res=0;bool fl=0;char c=0;while(!isdigit(c)) fl|=c=='-',c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return fl?-res:res;
}
void upd(int x,int w) {vl1[x]+=w;vl2[(x-1)/B+1]+=w;} 
ll qSm(int x)
{
	int t=(x-1)/B;ll res=0;for(int i=1;i<=t;++i) res+=vl2[i];
	for(int i=x;i>t*B;--i) res+=vl1[i];return res;
} 
void slv(int x,int m)
{
	m1=0;for(int i=1;i<=n;++i) rv[p[i]]=i,vl1[i]=vl2[i]=p1[i]=id[i]=tg[i]=0,vc[i].clear();
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<3;++j) a[i].F[j]=rd();
		if(a[i].F[0]==1) vc[a[i].F[2]].pb((Node) {i,1}),vc[a[i].F[1]-1].pb((Node) {i,-1});
		if(a[i].F[0]==3) vs[a[i].F[1]]=vs[a[i].F[2]]=x;
	}for(int i=1;i<=n;++i) if(vs[rv[i]]==x) {tg[i]=++m1;for(int j=i;;j=p[j]) {id[j]=i;if(vs[j]==x) break;}}
	for(int i=1,cnt;i<=n;++i) if(!id[i])
	{id[i]=i;cnt=1;for(int j=p[i];j!=i;j=p[j]) id[j]=i,++cnt;if(cnt>B) tg[i]=++m1;}
	for(int i=0;i<=m1;++i) nw[i]=0;for(int i=1;i<=m;++i) for(int j=1;j<=m1;++j) z[i][j]=0;
	for(int i=1;i<=n;++i) if(id[i]==i) {if(vs[rv[i]]==x) p1[id[rv[i]]]=i;else p1[i]=i;}
	for(int i=1;i<=n;++i) {++nw[tg[id[i]]];for(auto j:vc[i]) for(int k=1;k<=m1;++k) z[j.x][k]+=nw[k]*j.w;}
	for(int i=0;i<=m1;++i) nw[i]=0;
	for(int i=1,l,r,t,w;i<=m;++i)
	{
		if(a[i].F[0]==1)
		{
			l=a[i].F[1];r=a[i].F[2];ll res=s[r]-s[l-1]+qSm(r)-qSm(l-1);
			for(int j=1;j<=m1;++j) res+=nw[j]*z[i][j];printf("%lld\n",res);
		}
		if(a[i].F[0]==2)
		{
			t=id[a[i].F[1]];w=a[i].F[2];
			if(!tg[t]) {upd(t,w);for(int j=p[t];j!=t;j=p[j]) upd(j,w);continue;}
			nw[tg[t]]+=w;for(int j=p1[t];j!=t;j=p1[j]) nw[tg[j]]+=w;
		}if(a[i].F[0]==3) swap(p1[id[a[i].F[1]]],p1[id[a[i].F[2]]]),swap(p[a[i].F[1]],p[a[i].F[2]]);
	}for(int i=n;i;--i) s[i]-=s[i-1];for(int i=1;i<=n;++i) s[i]+=s[i-1]+vl1[i]+nw[tg[id[i]]];
}
int main()
{
	n=rd();for(int i=1;i<=n;++i) s[i]=s[i-1]+rd();for(int i=1;i<=n;++i) p[i]=rd();
	m=rd();for(int i=1;i<=m;i+=B) slv(i,min(m-i+1,B));return 0;
}