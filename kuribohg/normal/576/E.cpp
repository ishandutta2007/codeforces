#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;
const int MAXN=500010;
int n,m,k,Qnum,col[MAXN],nowStep[MAXN];
pair<int,int> E[MAXN],Q[MAXN];
vector<int> t[MAXN];
bool ans[MAXN];
struct Rec
{
	int col,x,y,fa,w,d;
};
struct UnionFindSet
{
	int fa[MAXN],w[MAXN],d[MAXN];
	void reset(int n)
	{
		for(int i=1;i<=n;i++)
			fa[i]=i;
	}
	pair<int,int> find(int x)
	{
		if(fa[x]==x) return make_pair(x,w[x]);
		pair<int,int> p=find(fa[x]);
		return make_pair(p.first,p.second^w[x]);
	}
	Rec uni(int i,int j)
	{
		pair<int,int> Fi=find(i),Fj=find(j);
		int fi=find(i).first,fj=find(j).first;
		if(d[fi]>d[fj]) swap(fi,fj);
		Rec r;
		r.x=fi;
		r.y=fj;
		r.fa=fa[fi];
		r.w=w[fi];
		r.d=d[fj];
		fa[fi]=fj,w[fi]=Fi.second^Fj.second^1;
		if(d[fi]==d[fj]) d[fj]++;
		return r;
	}
}UFS[51];
struct Seg
{
	int l,r;
	vector<int> v;
	vector<int> col;
	vector<int> type;
	vector<int> id;
}T[MAXN<<2];
void MakeTree(int x,int l,int r)
{
	T[x].l=l,T[x].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	MakeTree(x<<1,l,mid);
	MakeTree(x<<1|1,mid+1,r);
}
void Insert(int x,int l,int r,const pair<int,int> &P,int op,int id)
{
	if(l>r) return;
	if(T[x].l==l&&T[x].r==r)
	{
		T[x].v.push_back(P.first);
		T[x].col.push_back(P.second);
		T[x].type.push_back(op);
		T[x].id.push_back(id);
		return;
	}
	int mid=(T[x].l+T[x].r)>>1;
	if(r<=mid) Insert(x<<1,l,r,P,op,id);
	else if(l>mid) Insert(x<<1|1,l,r,P,op,id);
	else Insert(x<<1,l,mid,P,op,id),Insert(x<<1|1,mid+1,r,P,op,id);
}
void DFS(int x)
{
	vector<Rec> rec;
	for(int i=0;i<T[x].v.size();i++)
	{
		if(T[x].type[i]==1) continue;
		pair<int,int> fi=UFS[T[x].col[i]].find(E[T[x].v[i]].first);
		pair<int,int> fj=UFS[T[x].col[i]].find(E[T[x].v[i]].second);
		if(fi==fj)
		{
			ans[T[x].id[i]]=false;
			continue;
		}
		ans[T[x].id[i]]=true;
		Rec r=UFS[T[x].col[i]].uni(E[T[x].v[i]].first,E[T[x].v[i]].second);
		r.col=T[x].col[i];
		rec.push_back(r);
	}
	for(int i=T[x].v.size()-1;i>=0;i--)
	{
		if(T[x].type[i]==0) continue;
		pair<int,int> fi=UFS[T[x].col[i]].find(E[T[x].v[i]].first);
		pair<int,int> fj=UFS[T[x].col[i]].find(E[T[x].v[i]].second);
		if(fi==fj)
		{
			ans[T[x].id[i]]=false;
			if(col[T[x].v[i]])
				Insert(1,t[T[x].v[i]][nowStep[T[x].v[i]]]+1,t[T[x].v[i]][nowStep[T[x].v[i]]+1]-1,make_pair(T[x].v[i],col[T[x].v[i]]),0,0);
			nowStep[T[x].v[i]]++;
			continue;
		}
		ans[T[x].id[i]]=true;
		col[T[x].v[i]]=T[x].col[i];
		Rec r=UFS[T[x].col[i]].uni(E[T[x].v[i]].first,E[T[x].v[i]].second);
		r.col=T[x].col[i];
		rec.push_back(r);
		Insert(1,t[T[x].v[i]][nowStep[T[x].v[i]]]+1,t[T[x].v[i]][nowStep[T[x].v[i]]+1]-1,make_pair(T[x].v[i],T[x].col[i]),0,0);
		nowStep[T[x].v[i]]++;
	}
	if(T[x].l!=T[x].r)
	{
		DFS(x<<1);
		DFS(x<<1|1);
	}
	for(int i=rec.size()-1;i>=0;i--)
	{
		int col=rec[i].col,x=rec[i].x;
		UFS[col].fa[x]=rec[i].fa;
		UFS[col].w[x]=rec[i].w;
		UFS[col].d[rec[i].y]=rec[i].d;
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&Qnum);
	for(int i=1;i<=k;i++) UFS[i].reset(n);
	for(int i=1;i<=m;i++) scanf("%d%d",&E[i].first,&E[i].second);
	for(int i=1;i<=Qnum;i++) scanf("%d%d",&Q[i].first,&Q[i].second),t[Q[i].first].push_back(i);
	for(int i=1;i<=m;i++) t[i].push_back(Qnum+1);
	MakeTree(1,1,Qnum);
	for(int i=1;i<=Qnum;i++) Insert(1,i,i,Q[i],1,i);
	DFS(1);
	for(int i=1;i<=Qnum;i++)
		if(ans[i]) puts("YES");
		else puts("NO");
	return 0;
}