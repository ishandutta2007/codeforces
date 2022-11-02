#include<bits/stdc++.h>
using namespace std;
struct edge{int to,nxt;}e[40005];
struct node{int a,b,c;bool operator<(node y) const {return a<y.a||(a==y.a&&b<y.b)||(a==y.a&&b==y.b&&c<y.c);}};
int n,m,k,et,head[3005],d[3005][3005],l[3005][3005];map<node,char>mp;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void paint(int x,int ls) {if(x) paint(ls,l[x][ls]),printf("%d ",x);}
inline void bfs(int s,int t)
{
	queue<pair<int,int> >q;q.push(make_pair(s,0)),memset(d,0,sizeof(d)),d[s][0]=1;
	while(!q.empty())
	{
		int x=q.front().first,ls=q.front().second;q.pop();
		if(x==t) {printf("%d\n",d[x][ls]-1),paint(x,ls),putchar('\n');return;}
		for(int i=head[x];i;i=e[i].nxt)
			if(!mp[(node){ls,x,e[i].to}]&&!d[e[i].to][x])
				d[e[i].to][x]=d[x][ls]+1,q.push(make_pair(e[i].to,x)),l[e[i].to][x]=ls;
	}
	puts("-1");
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y),adde(y,x);
	for(int i=1,a,b,c;i<=k;i++) scanf("%d%d%d",&a,&b,&c),mp[(node){a,b,c}]=1;
	return bfs(1,n),0;
}