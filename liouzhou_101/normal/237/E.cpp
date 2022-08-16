#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int cnt[30];

string t;

int n;
string s[110];
int a[110];

int S,T;

const int MaxN=1000010;

int tot;
struct node
{
	int from,way,cap,cost;
	node *next,*rev;
}edge[MaxN],*vec[MaxN];

void addedge(int x,int y,int c,int w)
{
	++tot;
	edge[tot].from=x;
	edge[tot].way=y;
	edge[tot].cap=c;
	edge[tot].cost=w;
	edge[tot].next=vec[x];
	edge[tot].rev=&edge[tot+1];
	vec[x]=&edge[tot];
	++tot;
	edge[tot].from=y;
	edge[tot].way=x;
	edge[tot].cap=0;
	edge[tot].cost=-w;
	edge[tot].next=vec[y];
	edge[tot].rev=&edge[tot-1];
	vec[y]=&edge[tot];
}

const int INF=1000000000;

int ans,flow;
int dis[MaxN];
node *pre[MaxN];
priority_queue<pair<int,int> > H;

bool SPFA()
{
	for (int i=1;i<=T;++i)
		dis[i]=INF;
	H.push(make_pair(dis[S]=0,S));
	while (!H.empty())
	{
		int nowx=H.top().second,nowd=-H.top().first;
		H.pop();
		if (dis[nowx]!=nowd) continue;
		for (node *it=vec[nowx];it;it=it->next)
			if (it->cap>0) if (dis[it->way]>nowd+it->cost)
			{
				H.push(make_pair(-(dis[it->way]=nowd+it->cost),it->way));
				pre[it->way]=it;
			}
	}
	if (dis[T]==INF) return false;
	flow+=1;
	ans+=dis[T];
	for (int i=T;i!=S;i=pre[i]->from)
	{
		pre[i]->cap-=1;
		pre[i]->rev->cap+=1;
	}
	return true;
}

int main()
{
	cin>>t;
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>s[i]>>a[i];
		a[i]=min(a[i],(int)s[i].length());
	}
	S=200;
	T=S+1;
	memset(cnt,0,sizeof(cnt));
	for (int i=0;i<t.length();++i)
		cnt[t[i]-'a'+1]++;
	for (int i=1;i<=26;++i)
		addedge(S,i,cnt[i],0);
	for (int i=1;i<=n;++i)
	{
		addedge(26+i,T,a[i],i);
		memset(cnt,0,sizeof(cnt));
		for (int j=0;j<s[i].length();++j)
			cnt[s[i][j]-'a'+1]++;
		for (int j=1;j<=26;++j)
			addedge(j,26+i,cnt[j],0);
	}
	while (SPFA());
	if (flow!=t.length()) ans=-1;
	cout<<ans<<endl;
	return 0;
}