#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
const int MAXN=200010;
int n,m,p[MAXN],pos[MAXN],tot;
pair<int,int> P[MAXN*20];
int BIT[MAXN];
inline void Change(int x)
{
	for(int i=x;i<=n;i+=(i&(-i)))
		BIT[i]++;
}
inline int Query(int x)
{
	int con=0;
	for(int i=x;i;i^=(i&(-i)))
		con+=BIT[i];
	return con;
}
struct Node
{
	int x,l,r,type,id;
	friend bool operator<(const Node &p,const Node &q)
	{
		return p.x<q.x;
	}
}Q[MAXN*2];
int N,cur=1,ans[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) pos[p[i]]=i;
	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		for(int j=x;j<=n;j+=x)
			P[++tot]=make_pair(i,pos[j]);
	}
	sort(P+1,P+tot+1);
	for(int i=1;i<=m;i++)
	{
		int L,R;
		scanf("%d%d",&L,&R);
		++N,Q[N].x=L-1,Q[N].l=L,Q[N].r=R,Q[N].type=-1,Q[N].id=i;
		++N,Q[N].x=R,Q[N].l=L,Q[N].r=R,Q[N].type=1,Q[N].id=i;
	}
	sort(Q+1,Q+N+1);
	for(int i=1;i<=N;i++)
	{
		while(cur<=tot&&P[cur].first<=Q[i].x) Change(P[cur].second),cur++;
		if(Q[i].type==-1) ans[Q[i].id]-=Query(Q[i].r)-Query(Q[i].l-1);
		else ans[Q[i].id]+=Query(Q[i].r)-Query(Q[i].l-1);
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}