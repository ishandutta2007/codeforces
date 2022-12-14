#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn=5555550;
int n,m,x,prime[2222222],cnt,cur,sz,l[222222][15],r[222222][15],lp,rp,ct,to,val,treel[888888][15],treer[888888][15];
vector<int> v[222222];
vector<pair<int,int> > s[5555555];
bool f[5555555];
deque<pair<int,int> > q;
void buildl(int lp,int rp,int node,int i)
{
	if (lp==rp)
	{
		if (lp<=n) treel[node][i]=l[lp][i];
		else treel[node][i]=0;
		return;
	}
	int mid=(lp+rp)/2;
	buildl(lp,mid,node*2,i);
	buildl(mid+1,rp,node*2+1,i);
	treel[node][i]=max(treel[node*2][i],treel[node*2+1][i]);
}
void buildr(int lp,int rp,int node,int i)
{
	if (lp==rp)
	{
		if (lp<=n) treer[node][i]=r[lp][i];
		else treer[node][i]=1e9;
		return;
	}
	int mid=(lp+rp)/2;
	buildr(lp,mid,node*2,i);
	buildr(mid+1,rp,node*2+1,i);
	treer[node][i]=min(treer[node*2][i],treer[node*2+1][i]);
}
int queryl(int beg,int en,int l,int r,int node,int i)
{
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en) return treel[node][i];
	int mid=(l+r)/2;
	return max(queryl(beg,en,l,mid,node*2,i),queryl(beg,en,mid+1,r,node*2+1,i));
}
int queryr(int beg,int en,int l,int r,int node,int i)
{
	if (l>en || r<beg) return 1e9;
	if (l>=beg && r<=en) return treer[node][i];
	int mid=(l+r)/2;
	return min(queryr(beg,en,l,mid,node*2,i),queryr(beg,en,mid+1,r,node*2+1,i));
}
int main()
{
	for (int i=2;i<=maxn;i++)
	{
		if (!f[i])
		{
			for (int j=i+i;j<=maxn;j+=i) f[j]=1;
		}
	}
	for (int i=2;i<=maxn;i++) 
	{
		if (!f[i]) prime[++cnt]=i;
	}
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for (int j=1;j<=700;j++)
		{
			cur=0;
			while(x%prime[j]==0)
			{
				x/=prime[j];
				cur^=1;
			}
			if (cur) v[i].push_back(prime[j]);
		}
		if (x>1) v[i].push_back(x); 
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<(1<<(int)v[i].size());j++)
		{
			cur=1;ct=0;
			for (int k=0;k<v[i].size();k++)
			{
				if (j&(1<<k)) 
				{
					cur*=v[i][k];
					ct++;
				}
			}
			s[cur].push_back(make_pair(i,(int)v[i].size()-ct)); 
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=14;j++) r[i][j]=1e9;
	}
	for (int i=1;i<=5555550;i++)
	{
		if (s[i].size()<2) continue;
		q.clear();
		for (int j=0;j<s[i].size();j++)
		{
			to=s[i][j].first;val=s[i][j].second;
			for (int k=0;k<q.size();k++)
			{
				l[to][q[k].second+val]=max(l[to][q[k].second+val],q[k].first);
			}
			while(!q.empty())
			{
				if (q.front().second>=val) q.pop_front();
				else break;
			}
			q.push_front(make_pair(to,val)); 
		}
		q.clear();
		for (int j=(int)s[i].size()-1;j>=0;j--)
		{
			to=s[i][j].first;val=s[i][j].second;
			for (int k=0;k<q.size();k++)
			{
				r[to][q[k].second+val]=min(r[to][q[k].second+val],q[k].first);
			}
			while(!q.empty())
			{
				if (q.front().second>=val) q.pop_front();
				else break;
			}
			q.push_front(make_pair(to,val));
		}
	}
	sz=1;
	while(sz<n) sz*=2;
	for (int i=0;i<=14;i++)
	{
		buildl(1,sz,1,i);
		buildr(1,sz,1,i);
	}
	while(m--)
	{
		scanf("%d%d",&lp,&rp);
		for (int i=0;i<=14;i++)
		{
			if (queryl(lp,rp,1,sz,1,i)>=lp || queryr(lp,rp,1,sz,1,i)<=rp) 
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}