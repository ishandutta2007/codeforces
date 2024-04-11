#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<vector>
#define next next2
using namespace std;
const int MAXN=200010;
const int INF=1000000000;
int n,l,r;
int head[MAXN],to[MAXN],next[MAXN],w[MAXN],cnt=1;
int ans;
pair<int,int> Ans;
inline void adde(int f,int t,int ww)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=ww;
}
bool used[MAXN];
int root,size[MAXN],D[MAXN],K;
void getroot(int x,int fa)
{
	size[x]=1,D[x]=0;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa&&!used[to[i]])
		{
			getroot(to[i],x);
			size[x]+=size[to[i]];
			D[x]=max(D[x],size[to[i]]);
		}
	D[x]=max(D[x],K-size[x]);
	if(D[x]<D[root]) root=x;
}
int L,R,mid,check_ans;
int maxdep,Max[MAXN],Sub[MAXN];
int MaxDep,PreMax[MAXN],PreSub[MAXN];
int MaxD[MAXN];
pair<int,int> check_Ans;
vector<pair<int,int> > son_list;
int q[MAXN],ql,qr;
void DFS(int x,int fa,int ans,int len,int dep,int type=1)
{
	maxdep=max(maxdep,dep);
	if(type==1&&len>Max[dep]) Max[dep]=len,Sub[dep]=x;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa&&!used[to[i]])
			DFS(to[i],x,ans,(w[i]>=ans?1:-1)+len,dep+1,type);
}
bool cmp_MaxD(pair<int,int> i,pair<int,int> j)
{
	return MaxD[i.first]<MaxD[j.first];
}
bool check(int x,int ans,int N)
{
	MaxDep=0;
	for(int i=0;i<=N;i++) Max[i]=-INF,PreMax[i]=-INF;
	son_list.clear();
	for(int i=head[x];i;i=next[i])
		if(!used[to[i]])
		{
			maxdep=0;
			DFS(to[i],x,ans,(w[i]>=ans?1:-1),1,0);
			son_list.push_back(make_pair(to[i],(w[i]>=ans?1:-1)));
			MaxD[to[i]]=maxdep;
		}
	sort(son_list.begin(),son_list.end(),cmp_MaxD);
	PreMax[0]=0,PreSub[0]=x,check_ans=-INF;
	for(int i=0;i<son_list.size();i++)
	{
		maxdep=0;
		DFS(son_list[i].first,x,ans,son_list[i].second,1);
		ql=1,qr=0;
		for(int i=min(r,maxdep);i>l;i--)
		{
			while(qr>=ql&&Max[i]>=Max[q[qr]]) qr--;
			q[++qr]=i;
		}
		for(int i=0;i<=MaxDep;i++)
		{
			if(l-i<=maxdep&&l-i>=0)
			{
				while(qr>=ql&&Max[l-i]>=Max[q[qr]]) qr--;
				q[++qr]=l-i;
			}
			while(qr>=ql&&q[ql]>r-i) ql++;
			if(ql<=qr&&Max[q[ql]]+PreMax[i]>=check_ans) check_ans=Max[q[ql]]+PreMax[i],check_Ans=make_pair(PreSub[i],Sub[q[ql]]);
		}
		for(int i=0;i<=maxdep;i++)
			if(Max[i]>PreMax[i]) PreMax[i]=Max[i],PreSub[i]=Sub[i];
		for(int i=0;i<=maxdep;i++) Max[i]=-INF;
		MaxDep=maxdep;
	}
	if(check_ans>=0) return true;
	return false;
}
void work(int x)
{
	root=0;
	getroot(x,-1);
	used[root]=true;
	int rt=root;
	L=ans,R=INF;
	while(L<R)
	{
		mid=(L+R+1)>>1;
		if(check(rt,mid,size[x])) L=mid;
		else R=mid-1;
	}
	if(check(rt,L,size[x])) ans=L,Ans=check_Ans;
	if(!used[x]) K-=size[rt],work(x);
	for(int i=head[rt];i;i=next[i])
		if(!used[to[i]]) K=size[to[i]],work(to[i]);
}
int main()
{
	//freopen("data.in","r",stdin);
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1,x,y,z;i<n;i++) scanf("%d%d%d",&x,&y,&z),adde(x,y,z);
	for(int i=0;i<=n;i++) Max[i]=-INF;
	D[0]=INF,K=n;
	work(1);
	printf("%d %d\n",Ans.first,Ans.second);
	return 0;
}