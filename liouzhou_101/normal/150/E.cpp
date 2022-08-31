#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=100010;
const int INF=1000000000;

int n,limitL,limitR;
vector<pair<int,int> > v[MaxN];
vector<int> p;

void init()
{
	cin>>n>>limitL>>limitR;
	for (int i=1;i<n;++i)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		v[x].push_back(make_pair(y,c));
		v[y].push_back(make_pair(x,c));
		p.push_back(c);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	for (int i=1;i<=n;++i)
		for (vector<pair<int,int> >::iterator it=v[i].begin();it!=v[i].end();++it)
			it->second=lower_bound(p.begin(),p.end(),it->second)-p.begin();
}

int ans=-1,ansx,ansy;

int head,tail,Q[MaxN];
int used[MaxN],size[MaxN],most[MaxN],pre[MaxN];

vector<pair<int,int> > son[MaxN];
int len[MaxN],dis[MaxN],cost[MaxN];

bool cmp_len(pair<int,int> x,pair<int,int> y)
{
	return len[x.first]<len[y.first];
}

int top;
int F[MaxN],tmp[MaxN],from_F[MaxN],from_tmp[MaxN];

bool check(int root,int get)
{
	F[top=0]=0;
	from_F[0]=root;
	for (vector<pair<int,int> >::iterator it=son[root].begin();it!=son[root].end();++it)
	{
		used[Q[head=tail=1]=it->first]=1;
		from_tmp[0]=it->first;
		for (int i=1;i<=len[it->first];++i)
			tmp[i]=-INF;
		cost[it->first]=(it->second>=get)?1:-1;
		while (head<=tail)
		{
			int now=Q[head++];
			for (vector<pair<int,int> >::iterator p=v[now].begin();p!=v[now].end();++p)
				if (!used[p->first])
				{
					used[Q[++tail]=p->first]=1;
					cost[p->first]=cost[now]+((p->second>=get)?1:-1);
				}
		}
		for (int k=1;k<=tail;++k)
		{
			int i=Q[k];
			used[i]=0;
			tmp[dis[i]]=max(tmp[dis[i]],cost[i]);
			if (tmp[dis[i]]==cost[i]) from_tmp[dis[i]]=i;
		}
		head=1;
		tail=0;
		for (int i=top,j=0;i>=0;--i)
		{
			if (i>limitR) continue;
			while (j<=len[it->first]&&i+j<=limitR)
			{
				while (head<=tail&&tmp[Q[tail]]<tmp[j]) --tail;
				Q[++tail]=j++;
			}
			while (head<=tail&&i+Q[head]<limitL) ++head;
			if (head<=tail) if (F[i]+tmp[Q[head]]>=0)
			{
				if (get>ans)
				{
					ans=get;
					ansx=from_F[i];
					ansy=from_tmp[Q[head]];
				}
				return true;
			}
		}
		for (int i=1;i<=len[it->first];++i)
		{
			if (i>top)
			{
				F[i]=tmp[i];
				from_F[i]=from_tmp[i];
			}
			else if (F[i]<tmp[i])
			{
				F[i]=tmp[i];
				from_F[i]=from_tmp[i];
			}
		}
		top=len[it->first];
	}
	return false;
}

void solve(int x)
{
	used[Q[head=tail=1]=x]=1;
	while (head<=tail)
	{
		int now=Q[head++];
		size[now]=1;
		most[now]=0;
		for (vector<pair<int,int> >::iterator it=v[now].begin();it!=v[now].end();++it)
			if (!used[it->first])
			{
				used[Q[++tail]=it->first]=1;
				pre[it->first]=now;
			}
	}
	if (limitL>tail) return;
	int root=Q[tail];
	for (int k=tail;k>=1;--k)
	{
		int i=Q[k];
		size[pre[i]]+=size[i];
		most[pre[i]]=max(most[pre[i]],size[i]);
		most[i]=max(most[i],tail-size[i]);
		used[i]=0;
		if (most[i]<most[root]) root=i;
	}
	used[root]=1;
	for (vector<pair<int,int> >::iterator it=v[root].begin();it!=v[root].end();++it)
		if (!used[it->first])
		{
			son[root].push_back(*it);
			used[Q[head=tail=1]=it->first]=1;
			len[it->first]=dis[it->first]=1;
			while (head<=tail)
			{
				int now=Q[head++];
				for (vector<pair<int,int> >::iterator p=v[now].begin();p!=v[now].end();++p)
					if (!used[p->first])
					{
						used[Q[++tail]=p->first]=1;
						dis[p->first]=dis[now]+1;
						len[it->first]=max(len[it->first],dis[p->first]);
					}
			}
			for (int i=1;i<=tail;++i)
				used[Q[i]]=0;
		}
	sort(son[root].begin(),son[root].end(),cmp_len);
	int L=0,R=p.size()-1;
	while (L<=R)
	{
		int mid=(L+R)>>1;
		if (check(root,mid))
			L=mid+1;
		else
			R=mid-1;
	}
	for (vector<pair<int,int> >::iterator it=son[root].begin();it!=son[root].end();++it)
		solve(it->first);
}

void work()
{
	solve(1);
	cout<<ansx<<" "<<ansy<<endl;
}

int main()
{
	init();
	work();
	return 0;
}