#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=300010;

int n;
int p[MaxN],v[MaxN];

long long ans;

struct node
{
	node *Lc,*Rc;
	int L,R,mid;
	int val,delta;
	int cnt1,cnt2;
};

struct segment_tree
{
	node *root;
	int tot;
	node tree[MaxN*2];
	node *build(int L,int R)
	{
		node *it=&tree[++tot];
		it->L=L;
		it->R=R;
		it->cnt1=R-L+1;
		if (L<R)
		{
			it->mid=(L+R)>>1;
			it->Lc=build(L,it->mid);
			it->Rc=build(it->mid+1,R);
		}
		return it;
	}
	void clear(node *it)
	{
		if (it->delta)
		{
			it->Lc->delta+=it->delta;
			it->Rc->delta+=it->delta;
			it->Lc->val+=it->delta;
			it->Rc->val+=it->delta;
			it->delta=0;
		}
	}
	void update(node *it)
	{
		it->val=min(it->Lc->val,it->Rc->val);
		it->cnt1=it->cnt2=0;
		if (it->Lc->val==it->val)
		{
			it->cnt1+=it->Lc->cnt1;
			it->cnt2+=it->Lc->cnt2;
		}
		else if (it->Lc->val==it->val+1)
			it->cnt2+=it->Lc->cnt1;
		if (it->Rc->val==it->val)
		{
			it->cnt1+=it->Rc->cnt1;
			it->cnt2+=it->Rc->cnt2;
		}
		else if (it->Rc->val==it->val+1)
			it->cnt2+=it->Rc->cnt1;
	}
	void add(node *it,int L,int R,int p)
	{
		if (it->L==L&&it->R==R)
		{
			it->delta+=p;
			it->val+=p;
			return;
		}
		clear(it);
		if (R<=it->mid)
			add(it->Lc,L,R,p);
		else if (L>it->mid)
			add(it->Rc,L,R,p);
		else
		{
			add(it->Lc,L,it->mid,p);
			add(it->Rc,it->mid+1,R,p);
		}
		update(it);
	}
	void solve(node *it,int L,int R)
	{
		if (it->L==L&&it->R==R)
		{
			if (it->val<=2) ans+=it->cnt1;
			if (it->val==1) ans+=it->cnt2;
			return;
		}
		clear(it);
		if (R<=it->mid)
			solve(it->Lc,L,R);
		else if (L>it->mid)
			solve(it->Rc,L,R);
		else
		{
			solve(it->Lc,L,it->mid);
			solve(it->Rc,it->mid+1,R);
		}
	}
	void init(int L,int R)
	{
		root=build(L,R);
	}
	void add(int L,int R,int p)
	{
		add(root,L,R,p);
	}
	void solve(int L,int R)
	{
		solve(root,L,R);
	}
}T;

void init()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		p[x]=i;
	}
	T.init(1,n);
}

void work()
{
	for (int i=n;i>=1;--i)
	{
		v[p[i]]=i;
		int x=v[p[i]+1],y=v[p[i]-1];
		if (x>y) swap(x,y);
		if (!x&&!y)
			T.add(i,n,1);
		else if (!x)
			T.add(i,y-1,1);
		else
		{
			T.add(i,x-1,1);
			T.add(y,n,-1);
		}
		T.solve(i,n);
	}
	cout<<ans-n<<endl;
}

int main()
{
	init();
	work();
	return 0;
}