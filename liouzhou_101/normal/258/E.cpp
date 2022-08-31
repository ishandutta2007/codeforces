#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

const int MaxN=100010;

int n,m;
vector<int> v[MaxN];
vector<int> w;
int Lp[MaxN],Rp[MaxN];

void DFS(int x,int p)
{
	Lp[x]=Rp[x]=w.size();
	w.push_back(x);
	for (vector<int>::iterator it=v[x].begin();it!=v[x].end();++it)
		if (*it!=p)
		{
			DFS(*it,x);
			Rp[x]=w.size()-1;
		}
}

int x[MaxN],y[MaxN];
vector<int> p[MaxN],q[MaxN];

int tot;

struct node
{
	node *Lc,*Rc;
	int L,R,mid;
	int val,num,add;
}tree[MaxN*2],*root;

node *build(int L,int R)
{
	node *it=&tree[++tot];
	it->L=L;
	it->R=R;
	it->num=R-L+1;
	if (L<R)
	{
		it->mid=(L+R)>>1;
		it->Lc=build(L,it->mid);
		it->Rc=build(it->mid+1,R);
	}
	return it;
}

void init()
{
	cin>>n>>m;
	for (int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	DFS(1,0);
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		if (Lp[x[i]]>Lp[y[i]]) swap(x[i],y[i]);
		if (Rp[x[i]]<Lp[y[i]])
		{
			p[Lp[x[i]]].push_back(i);
			q[Rp[x[i]]].push_back(i);
			p[Lp[y[i]]].push_back(i);
			q[Rp[y[i]]].push_back(i);
		}
		else
		{
			p[Lp[x[i]]].push_back(i);
			q[max(Rp[x[i]],Rp[y[i]])].push_back(i);
		}
	}
	root=build(0,n-1);
}

int ans[MaxN];

void clear(node *it)
{
	if (it->add!=0)
	{
		it->Lc->add+=it->add;
		it->Rc->add+=it->add;
		it->Lc->val+=it->add;
		it->Rc->val+=it->add;
		it->add=0;
	}
}

void update(node *it)
{
	it->val=min(it->Lc->val,it->Rc->val);
	it->num=0;
	if (it->Lc->val==it->val) it->num+=it->Lc->num;
	if (it->Rc->val==it->val) it->num+=it->Rc->num;
}

void add(node *it,int x,int y,int p)
{
	if (it->L==x&&it->R==y)
	{
		it->add+=p;
		it->val+=p;
		return;
	}
	clear(it);
	if (y<=it->mid)
		add(it->Lc,x,y,p);
	else if (x>it->mid)
		add(it->Rc,x,y,p);
	else
	{
		add(it->Lc,x,it->mid,p);
		add(it->Rc,it->mid+1,y,p);
	}
	update(it);
}

void work()
{
	for (int i=0;i<n;++i)
	{
		for (vector<int>::iterator it=p[i].begin();it!=p[i].end();++it)
		{
			add(root,Lp[x[*it]],Rp[x[*it]],1);
			add(root,Lp[y[*it]],Rp[y[*it]],1);
		}
		if (root->val==0) ans[w[i]]=n-root->num-1; else ans[w[i]]=n-1;
		for (vector<int>::iterator it=q[i].begin();it!=q[i].end();++it)
		{
			add(root,Lp[x[*it]],Rp[x[*it]],-1);
			add(root,Lp[y[*it]],Rp[y[*it]],-1);
		}
	}
	for (int i=1;i<=n;++i)
		printf("%d ",max(ans[i],0));
}

int main()
{
	init();
	work();
	return 0;
}