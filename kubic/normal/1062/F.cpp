#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define LIM 1000005 
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int n,m,nw,s,ans,dg1[N],dg2[N],tmp[N],q[N];bool vs[N],tg[N],tg1[N];vector<int> e1[N],e2[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res; 
}
int main()
{
	n=rd();m=rd();q[0]=2;q[1]=1;
	for(int i=1,u,v;i<=m;++i) u=rd(),v=rd(),++dg1[v],++dg2[u],e1[u].pb(v),e2[v].pb(u);
	for(int i=1;i<=n;++i) {tmp[i]=dg1[i];if(!tmp[i]) q[++q[1]]=i;if(tmp[i]<2) for(auto j:e2[i]) vs[j]=1;}
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];if(q[0]>q[1]) tg[u]=1;if(q[0]==q[1]) tg1[u]=!vs[q[q[0]]];
		for(auto v:e1[u]) {--tmp[v];if(!tmp[v]) q[++q[1]]=v;if(tmp[v]<2) for(auto j:e2[v]) vs[j]=1;}
	}for(int i=1;i<=n;++i) vs[i]=0,q[i]=q[i+1];
	for(int i=1;i<=n;++i) {tmp[i]=dg2[i];if(!tmp[i]) ++nw,s^=i;if(tmp[i]<2) for(auto j:e1[i]) vs[j]=1;}
	for(int i=n,u;i;--i)
	{
		u=q[i];--nw;s^=u;if(nw==1) tg1[u]=tg[u]?!vs[s]:0,tg[u]=0;if(nw>1) tg[u]=tg1[u]=0;
		for(auto v:e2[u]) {--tmp[v];if(!tmp[v]) ++nw,s^=v;if(tmp[v]<2) for(auto j:e1[v]) vs[j]=1;}
	}for(int i=1;i<=n;++i) if(tg[i] || tg1[i]) ++ans;printf("%d\n",ans);return 0;
}