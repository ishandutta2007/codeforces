#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=100010;

int n,root;
int pre[MaxN];
vector<int> son[MaxN];
int head,tail,Q[MaxN];
int have[MaxN],next[MaxN],flag[MaxN],from[MaxN],rank[MaxN],dis[MaxN];

int get_LCA(int x,int y)
{
	while (from[x]!=from[y])
	{
		if (dis[from[x]]<dis[from[y]]) swap(x,y);
		x=pre[from[x]];
	}
	return (dis[x]<dis[y])?x:y;
}

int find_answer;

struct splay_node
{
	splay_node *pre,*son[2];
	int size,val;
};

struct splay_tree
{
	int tot;
	splay_node tree[MaxN*20];
	splay_node *root,*nil;
	void init()
	{
		root=nil=&tree[0];
		nil->pre=nil->son[0]=nil->son[1]=nil;
	}
	void rotate(splay_node *x,bool p)
	{
		splay_node *y=x->pre;
		if ((y->son[p^1]=x->son[p])!=nil)
			x->son[p]->pre=y;
		x->son[p]=y;
		if (y==y->pre->son[0])
			y->pre->son[0]=x;
		else if (y==y->pre->son[1])
			y->pre->son[1]=x;
		x->pre=y->pre;
		y->pre=x;
		y->size=y->son[0]->size+y->son[1]->size+1;
		x->size=x->son[0]->size+x->son[1]->size+1;
	}
	void splay(splay_node *x)
	{
		while (x->pre!=nil)
		{
			splay_node *y=x->pre;
			if (y->pre==nil)
				if (x==y->son[0])
					rotate(x,1);
				else
					rotate(x,0);
			else
				if (y==y->pre->son[0])
					if (x==y->son[0])
					{
						rotate(y,1);
						rotate(x,1);
					}
					else
					{
						rotate(x,0);
						rotate(x,1);
					}
				else
					if (x==y->son[0])
					{
						rotate(x,1);
						rotate(x,0);
					}
					else
					{
						rotate(y,0);
						rotate(x,0);
					}
		}
	}
	void insert(splay_node *&root,int val)
	{
		splay_node *it=&tree[++tot];
		it->val=val;
		it->size=1;
		it->pre=it->son[0]=it->son[1]=nil;
		if (root==nil)
		{
			root=it;
			return;
		}
		splay_node *x=root;
		while (1)
		{
			++x->size;
			if (x->val>val)
			{
				if (x->son[0]==nil)
				{
					x->son[0]=it;
					it->pre=x;
					break;
				}
				x=x->son[0];
			}
			else
			{
				if (x->son[1]==nil)
				{
					x->son[1]=it;
					it->pre=x;
					break;
				}
				x=x->son[1];
			}
		}
		splay(it);
		root=it;
	}
	int get_sum(splay_node *&root,int val)
	{
		if (root==nil) return 0;
		int get=0;
		splay_node *it=root,*tmp;
		while (it!=nil)
		{
			tmp=it;
			if (it->val>val)
			{
				get+=it->son[1]->size+1;
				it=it->son[0];
			}
			else
				it=it->son[1];
		}
		splay(tmp);
		root=tmp;
		return get;
	}
}H;

int tot;
struct segment_node
{
	segment_node *Lc,*Rc;
	int L,R,mid;
	splay_node *root;
}tree[MaxN*2];

int put[MaxN*2];

segment_node *top=&tree[0];

struct segment_tree
{
	int belong;
	segment_node *root;
	vector<int> list;
	segment_node *build(int L,int R)
	{
		segment_node *it=&tree[++tot];
		it->L=L;
		it->R=R;
		it->root=H.nil;
		if (L<R)
		{
			it->mid=(it->L+it->R)>>1;
			it->Lc=build(L,it->mid);
			it->Rc=build(it->mid+1,R);
		}
		return it;
	}
	void build(int _belong)
	{
		belong=_belong;
		for (int i=belong,k=0;i;i=next[i])
		{
			list.push_back(i);
			from[i]=belong;
			rank[i]=k++;
		}
		root=build(0,list.size()-1);
	}
	void add(segment_node *it,int x,int Time)
	{
		H.insert(it->root,Time);
		if (it->L==it->R) return;
		if (x<=it->mid)
			add(it->Lc,x,Time);
		else
			add(it->Rc,x,Time);
	}
	void add(int x,int Time)
	{
		add(root,rank[x],Time);
	}
	int get_sum(segment_node *it,int x,int y,int p)
	{
		if (it->L==x&&it->R==y)
			return put[it-top]=y-x+1-H.get_sum(it->root,p);
		if (y<=it->mid)
			return put[it-top]=get_sum(it->Lc,x,y,p);
		if (x>it->mid)
			return put[it-top]=get_sum(it->Rc,x,y,p);
		return put[it-top]=get_sum(it->Lc,x,it->mid,p)+get_sum(it->Rc,it->mid+1,y,p);
	}
	int get_sum(int x,int y,int p)
	{
		x=rank[x];
		y=rank[y];
		if (x>y) swap(x,y);
		return get_sum(root,x,y,p);
	}
	void get_answer(segment_node *it,int x,int y,int p,int k)
	{
		if (it->L==it->R)
		{
			find_answer=list[it->L];
			return;
		}
		if (y<=it->mid)
			get_answer(it->Lc,x,y,p,k);
		else if (x>it->mid)
			get_answer(it->Rc,x,y,p,k);
		else
		{
			int tmp;
			if (it->L==x&&it->R==y)
				tmp=get_sum(it->Lc,it->Lc->L,it->Lc->R,p);
			else
				tmp=put[it->Lc-top];
			if (tmp>=k)
				get_answer(it->Lc,x,it->mid,p,k);
			else
				get_answer(it->Rc,it->mid+1,y,p,k-tmp);
		}
	}
	void get_answer(int x,int y,int p,int k)
	{
		x=rank[x];
		y=rank[y];
		if (x>y) swap(x,y);
		get_answer(root,x,y,p,k);
	}
	void get_answer_rev(segment_node *it,int x,int y,int p,int k)
	{
		if (it->L==it->R)
		{
			find_answer=list[it->L];
			return;
		}
		if (y<=it->mid)
			get_answer_rev(it->Lc,x,y,p,k);
		else if (x>it->mid)
			get_answer_rev(it->Rc,x,y,p,k);
		else
		{
			int tmp;
			if (it->L==x&&it->R==y)
				tmp=get_sum(it->Rc,it->Rc->L,it->Rc->R,p);
			else
				tmp=put[it->Rc-top];
			if (tmp>=k)
				get_answer_rev(it->Rc,it->mid+1,y,p,k);
			else
				get_answer_rev(it->Lc,x,it->mid,p,k-tmp);
		}
	}
	void get_answer_rev(int x,int y,int p,int k)
	{
		x=rank[x];
		y=rank[y];
		if (x>y) swap(x,y);
		get_answer_rev(root,x,y,p,k);
	}
}T[MaxN];

vector<pair<int,int> > trip;

void find_way(int x,int u)
{
	trip.clear();
	x=pre[x];
	while (from[x]!=from[u])
	{
		trip.push_back(make_pair(x,from[x]));
		x=pre[from[x]];
	}
	if (x!=u)
		trip.push_back(make_pair(x,T[from[x]].list[rank[u]+1]));
}

void get_stop(int &k,int p)
{
	for (vector<pair<int,int> >::iterator it=trip.begin();it!=trip.end();++it)
	{
		int have=T[from[it->first]].get_sum(it->second,it->first,p);
		if (have>=k)
		{
			T[from[it->first]].get_answer(it->second,it->first,p,k);
			return;
		}
		k-=have;
	}
}

void get_stop_rev(int &k,int p)
{
	for (vector<pair<int,int> >::iterator it=trip.begin();it!=trip.end();++it)
	{
		int have=T[from[it->first]].get_sum(it->second,it->first,p);
		if (have>=k)
		{
			T[from[it->first]].get_answer_rev(it->second,it->first,p,k);
			return;
		}
		k-=have;
	}
}

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&pre[i]);
		son[pre[i]].push_back(i);
		if (!pre[i]) root=i;
	}
	Q[head=tail=1]=root;
	while (head<=tail)
	{
		int now=Q[head++];
		have[now]=1;
		for (vector<int>::iterator it=son[now].begin();it!=son[now].end();++it)
			dis[Q[++tail]=*it]=dis[now]+1;
	}
	for (int k=tail;k>=1;--k)
	{
		int i=Q[k];
		have[pre[i]]+=have[i];
		if (!son[i].empty())
		{
			int get,most=0;
			for (vector<int>::iterator it=son[i].begin();it!=son[i].end();++it)
				if (have[*it]>most) most=have[get=*it];
			flag[next[i]=get]=1;
		}
	}
	H.init();
	for (int i=1;i<=n;++i)
		if (!flag[i]) T[i].build(i);
}

void work()
{
	int Test;
	cin>>Test;
	for (int Time=1;Time<=Test;++Time)
	{
		int flag;
		scanf("%d",&flag);
		if (flag==1)
		{
			int x;
			scanf("%d",&x);
			T[from[x]].add(x,Time);
		}
		else
		{
			int x,y,k,p;
			scanf("%d%d%d%d",&x,&y,&k,&p);
			int u=get_LCA(x,y);
			find_answer=-1;
			if (x!=u)
			{
				find_way(x,u);
				get_stop_rev(k,p);
			}
			if (find_answer<0&&x!=u&&y!=u)
			{
				trip.clear();
				trip.push_back(make_pair(u,u));
				get_stop(k,p);
			}
			if (find_answer<0&&y!=u)
			{
				find_way(y,u);
				for (int i=0;i<trip.size()/2;++i)
					swap(trip[i],trip[trip.size()-i-1]);
				get_stop(k,p);
			}
			printf("%d\n",find_answer);
		}
	}
}

int main()
{
	init();
	work();
	return 0;
}