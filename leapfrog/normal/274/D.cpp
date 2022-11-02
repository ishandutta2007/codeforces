#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[100005<<1];
int tot=0,cnt=0,n,m,head[100005],deg[100005],ans[100005];vector<pair<int,int> >a;
inline void adde(int x,int y) {e[++tot]=(edge){y,head[x]},head[x]=tot,deg[y]++;}
inline bool cmp(int x,int y) {return a[x]<a[y];}
int main()
{
	scanf("%d%d",&m,&n),memset(head,0,sizeof(head)),cnt=n;
	for(int k=1;k<=m;k++)
	{
		a.clear(),a.push_back(make_pair(-1,-1));
		for(int i=1,x;i<=n;i++) scanf("%d",&x),a.push_back(make_pair(x,i));
		sort(a.begin()+1,a.end());vector<pair<int,int> >v;
		for(int i=1,j=i;i<=n;i=j+1,j=i) {while(j+1<=n&&a[j+1].first==a[i].first) j++;v.push_back(make_pair(i,j));}
		for(int j=0;j<(int)v.size()-1;j++)
		{
			int l1=v[j].first,r1=v[j].second,l2=v[j+1].first,r2=v[j+1].second;
			if(a[l1].first==-1) continue;else ++cnt;
			for(int i=l1;i<=r1;i++) adde(a[i].second,cnt);
			for(int i=l2;i<=r2;i++) adde(cnt,a[i].second);
		}
	}
	queue<int>q;tot=0;
	for(int i=1;i<=cnt;i++) if(!deg[i]) q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop(),ans[++tot]=x;
		for(int i=head[x];i;i=e[i].nxt) {deg[e[i].to]--;if(!deg[e[i].to]) q.push(e[i].to);}
	}
	if(tot!=cnt) return puts("-1"),0;
	for(int i=1;i<=cnt;i++) if(ans[i]<=n) printf("%d%c",ans[i],i==cnt?'\n':' ');
	return 0;
}