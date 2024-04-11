#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;
const int MAXN=20010;
const int INF=1000000000;
int n,P,Q_num,x,y;
int c[MAXN],w[MAXN],t[MAXN];
vector<pair<int,int> > Q[MAXN];
struct Seg
{
	int l,r;
	vector<pair<int,int> > A;
}T[MAXN<<2];
void MakeTree(int x,int l,int r)
{
	T[x].l=l,T[x].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	MakeTree(x<<1,l,mid);
	MakeTree(x<<1|1,mid+1,r);
}
void Change(int x,int l,int r,int c,int w)
{
	if(T[x].l==l&&T[x].r==r)
	{
		T[x].A.push_back(make_pair(c,w));
		return;
	}
	int mid=(T[x].l+T[x].r)>>1;
	if(r<=mid) Change(x<<1,l,r,c,w);
	else if(l>mid) Change(x<<1|1,l,r,c,w);
	else Change(x<<1,l,mid,c,w),Change(x<<1|1,mid+1,r,c,w);
}
int f[20][4010],ans[MAXN],res[MAXN];
void DFS(int x,int dep)
{
	int len=T[x].A.size();
	for(int i=0;i<=4000;i++) f[dep][i]=f[dep-1][i];
	for(int i=0;i<len;i++)
	{
		int c=T[x].A[i].first,w=T[x].A[i].second;
		for(int j=4000;j>=c;j--)
			f[dep][j]=max(f[dep][j],f[dep][j-c]+w);
	}
	if(T[x].l!=T[x].r) DFS(x<<1,dep+1),DFS(x<<1|1,dep+1);
	else
	{
		for(int j=0;j<=4000;j++) res[j]=f[dep][j];
		for(int j=1;j<=4000;j++) res[j]=max(res[j],res[j-1]);
		int Len=Q[T[x].l].size();
		for(int i=0;i<Len;i++)
		{
			int p=Q[T[x].l][i].first,id=Q[T[x].l][i].second;
			ans[id]=res[p];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&P);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&c[i],&w[i],&t[i]);
	scanf("%d",&Q_num);
	for(int i=1;i<=Q_num;i++)
	{
		scanf("%d%d",&x,&y);
		Q[x].push_back(make_pair(y,i));
	}
	MakeTree(1,1,20000);
	for(int i=1;i<=n;i++) Change(1,t[i],t[i]+P-1,c[i],w[i]);
	for(int i=1;i<=4000;i++) f[0][i]=-INF;
	DFS(1,1);
	for(int i=1;i<=Q_num;i++) printf("%d\n",ans[i]);
	return 0;
}