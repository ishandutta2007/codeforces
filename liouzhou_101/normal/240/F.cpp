#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MaxN=100010;

int n,m;
char s[MaxN];

int tot;
struct node
{
	node *Lc,*Rc;
	int L,R,mid;
	int flag;
	int v[26];
}tree[MaxN<<1],*root;

void clear(node *it)
{
	if (it->flag>=0)
	{
		it->Lc->flag=it->Rc->flag=it->flag;
		memset(it->Lc->v,0,sizeof(it->Lc->v));
		memset(it->Rc->v,0,sizeof(it->Rc->v));
		it->Lc->v[it->flag]=it->Lc->R-it->Lc->L+1;
		it->Rc->v[it->flag]=it->Rc->R-it->Rc->L+1;
		it->flag=-1;
	}
}

void update(node *it)
{
	for (int i=0;i<26;++i)
		it->v[i]=it->Lc->v[i]+it->Rc->v[i];
}

node *build(int L,int R)
{
	node *it=&tree[++tot];
	it->L=L;
	it->R=R;
	it->flag=-1;
	if (L==R)
		it->v[s[L]-'a']=1;
	else
	{
		it->mid=(L+R)>>1;
		it->Lc=build(it->L,it->mid);
		it->Rc=build(it->mid+1,it->R);
		update(it);
	}
	return it;
}

void add(node *it,int x,int y,int c)
{
	if (it->L==x&&it->R==y)
	{
		it->flag=c;
		memset(it->v,0,sizeof(it->v));
		it->v[c]=y-x+1;
		return;
	}
	clear(it);
	if (y<=it->mid)
		add(it->Lc,x,y,c);
	else if (x>it->mid)
		add(it->Rc,x,y,c);
	else
	{
		add(it->Lc,x,it->mid,c);
		add(it->Rc,it->mid+1,y,c);
	}
	update(it);
}

int tmp[26];

void get(node *it,int x,int y)
{
	if (it->L==x&&it->R==y)
	{
		for (int i=0;i<26;++i)
			tmp[i]+=it->v[i];
		return;
	}
	clear(it);
	if (y<=it->mid)
		get(it->Lc,x,y);
	else if (x>it->mid)
		get(it->Rc,x,y);
	else
	{
		get(it->Lc,x,it->mid);
		get(it->Rc,it->mid+1,y);
	}
}

void init()
{
	scanf("%d%d%s",&n,&m,s+1);
	root=build(1,n);
}

void solve(int x,int y)
{
	memset(tmp,0,sizeof(tmp));
	get(root,x,y);
	int flag=-1;
	for (int i=0;i<26;++i)
		if (tmp[i]&1)
		{
			if (flag>=0) return;
			--tmp[flag=i];
		}
	for (int i=0;i<26;++i)
	{
		if (!tmp[i]) continue;
		add(root,x,x+(tmp[i]>>1)-1,i);
		add(root,y-(tmp[i]>>1)+1,y,i);
		x+=tmp[i]>>1;
		y-=tmp[i]>>1;
	}
	if (flag>=0)
		add(root,x,y,flag);
}

void travel(node *it)
{
	if (it->flag>=0)
	{
		for (int i=it->L;i<=it->R;++i)
			putchar(it->flag+'a');
		return;
	}
	if (it->L==it->R)
	{
		for (int i=0;i<26;++i)
			if (it->v[i])
			{
				putchar(i+'a');
				break;
			}
		return;
	}
	travel(it->Lc);
	travel(it->Rc);
}

void work()
{
	while (m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		solve(x,y);
	}
	travel(root);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	work();
	return 0;
}