#include<bits/stdc++.h>
using namespace std;const int INF=(int)0x3f3f3f3f3f3f3f3f;
struct edge{int to,w,c,nxt;}e[100005];
int n,l,et,s,t,head[1005],ct[26],d[1005],f[1005],ls[1005];char c[105];
inline void ADDE(int x,int y,int w,int c) {e[++et]=(edge){y,w,c,head[x]},head[x]=et;}
inline void adde(int x,int y,int w,int c) {ADDE(x,y,w,c),ADDE(y,x,0,-c);}
inline char spfa(int s,int t)
{
	char v[1005];memset(v,0,sizeof(v)),memset(d,0x3f,sizeof(d));
	queue<int>q;q.push(s),f[s]=INF,d[s]=0,v[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop(),v[x]=0;
		for(int i=head[x];i;i=e[i].nxt) if(e[i].w&&d[e[i].to]>d[x]+e[i].c)
		{
			if(!v[e[i].to]) v[e[i].to]=1,q.push(e[i].to);
			d[e[i].to]=d[x]+e[i].c,f[e[i].to]=min(f[x],e[i].w),ls[e[i].to]=i;
		}
	}
	return d[t]!=INF;
}
#define rev(x) ((((x)&1)?1:-1)+(x))
inline void upd(int s,int t,int &fl,int &c)
{
	fl+=f[t],c+=f[t]*d[t];int x=t;
	while(x!=s) e[ls[x]].w-=f[t],e[rev(ls[x])].w+=f[t],x=e[rev(ls[x])].to;
}
inline int mcmf(int s,int t,int &c) {int f=0;while(spfa(s,t)) upd(s,t,f,c);return f;}
int main()
{
	scanf("%s%d",c+1,&n),l=strlen(c+1),s=1001,t=1002;
	for(int i=1;i<=l;i++) ct[c[i]-'a']++;
	for(int i=0;i<26;i++) adde(s,i+1,ct[i],0);
	for(int j=1;j<=n;j++)
	{
		scanf("%s",c+1),memset(ct,0,sizeof(ct));int len=strlen(c+1);
		for(int i=1;i<=len;i++) ct[c[i]-'a']++;
		for(int i=0;i<26;i++) adde(i+1,j+26,ct[i],0);
		int qaq;scanf("%d",&qaq),adde(j+26,t,qaq,j);
	}
	int q=0;if(mcmf(s,t,q)==l) printf("%d\n",q);else puts("-1");
}