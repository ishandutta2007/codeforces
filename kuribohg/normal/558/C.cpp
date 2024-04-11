#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<iterator>
using namespace std;
const int N=100000;
const int MAXN=200010;
const int INF=1000000000;
set<int> S;
int n,a[MAXN],ans=INF,d[MAXN];
bool used[MAXN];
void make_set()
{
	int p=a[1];
	while(p)
	{
		int x=p;
		while(x<=N) S.insert(x),x<<=1;
		p>>=1;
	}
	S.insert(0);
}
int q[MAXN],l,r;
void BFS(int S)
{
	for(int i=0;i<=N;i++) used[i]=false,d[i]=INF;
	d[S]=0,q[l=r=1]=S,used[S]=true;
	while(l<=r)
	{
		int x=q[l++];
		if(x%2==0&&!used[x>>1]) d[x>>1]=d[x]+1,q[++r]=x>>1,used[x>>1]=true;
		if(!used[x<<1]&&(x<<1)<=N) d[x<<1]=d[x]+1,q[++r]=x<<1,used[x<<1]=true;
		if(!used[x<<1|1]&&(x<<1|1)<=N) d[x<<1|1]=d[x]+1,q[++r]=x<<1|1,used[x<<1|1]=true;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	make_set();
	for(set<int>::iterator it=S.begin();it!=S.end();it++)
	{
		BFS(*it);
		int res=0;
		for(int i=1;i<=n;i++)
		{
			res+=d[a[i]];
			if(res>=INF) res=INF;
		}
		ans=min(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}