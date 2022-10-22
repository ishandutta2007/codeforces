#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define LIM 1000005
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int T,n,m,q[N],st1[N],st2[N],ans1[N],ans2[N];bool vs[N];
vector<int> ch[N];map<int,bool> e[N];struct List {int pr,sf;}ls[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
void dlt(int u) {ls[ls[u].pr].sf=ls[u].sf;ls[ls[u].sf].pr=ls[u].pr;}
void slv()
{
	n=rd();m=rd();ls[0].sf=1;st1[0]=st2[0]=0;
	for(int i=1;i<=n;++i)
		vs[i]=0,e[i].clear(),ch[i].clear(),ls[i]=(List) {i-1,(i<n?i+1:0)};
	for(int i=1,u,v;i<=m;++i) u=rd(),v=rd(),e[u][v]=e[v][u]=1;
	for(int i=1;i<=n;++i) if(!vs[i])
	{
		q[0]=2;q[1]=1;q[++q[1]]=i;dlt(i);
		while(q[0]<=q[1])
		{
			int u=q[q[0]++];
			for(int v=ls[0].sf;v;v=ls[v].sf)
				if(!e[u][v]) q[++q[1]]=v,dlt(v),ch[u].pb(v);
		}if(q[1]<3) {st1[++st1[0]]=i;st2[++st2[0]]=i;continue;}
		for(int j=q[1];j>1;--j)
		{
			bool fl=0;vs[q[j]]=1;st1[++st1[0]]=q[j];
			for(auto k:ch[q[j]]) if(!vs[k])
				vs[k]=1,st1[++st1[0]]=k,st2[++st2[0]]=k,fl=1;
			if(!fl) {vs[q[j]]=0;--st1[0];continue;}st2[++st2[0]]=q[j];
		}
		if(!vs[q[2]])
		{
			st2[st2[0]+1]=st2[st2[0]];
			st1[++st1[0]]=st2[st2[0]++]=q[2];
		}
	}for(int i=1;i<=n;++i) ans1[st1[i]]=i,ans2[st2[i]]=i;
	for(int i=1;i<=n;++i) printf("%d ",ans1[i]);putchar('\n');
	for(int i=1;i<=n;++i) printf("%d ",ans2[i]);putchar('\n'); 
}
int main() {T=rd();while(T--) slv();return 0;}