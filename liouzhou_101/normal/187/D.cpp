#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=100010;
const int INF=1000000010;

int n,g,r,T;
long long s[MaxN],F[MaxN];

int tot;
struct node
{
	int val;
	node *Lc,*Rc;
}tree[MaxN*30],*root;

void add(node *it,int L,int R,int x,int c)
{
	it->val=c;
	if (L+1==R) return;
	int mid=(L+R)>>1;
	if (x<mid)
	{
		if (!it->Lc)
			it->Lc=&tree[++tot];
		add(it->Lc,L,mid,x,c);
	}
	else
	{
		if (!it->Rc)
			it->Rc=&tree[++tot];
		add(it->Rc,mid,R,x,c);
	}
}

int get(node *it,int L,int R,int x,int y)
{
	if (!it) return INF;
	if (L==x&&R==y) return it->val;
	int mid=(L+R)>>1;
	if (y<=mid)
		return get(it->Lc,L,mid,x,y);
	if (x>=mid)
		return get(it->Rc,mid,R,x,y);
	return min(get(it->Lc,L,mid,x,mid),get(it->Rc,mid,R,mid,y));
}

void init()
{
	cin>>n>>g>>r;
	T=g+r;
	for (int i=0;i<=n;++i)
		scanf("%I64d",&s[i]);
	for (int i=n;i>=0;--i)
		s[i]+=s[i+1];
	root=&tree[++tot];
	root->val=INF;
	for (int i=n;i>=1;--i)
	{
		int L=((g-s[i])%T+T)%T,R=((-s[i])%T+T)%T;
		int j=(L<R)?get(root,0,T,L,R):min(get(root,0,T,0,R),get(root,0,T,L,T));
		if (j==INF)
			F[i]=s[i];
		else
			F[i]=s[i]-s[j]+T-(s[i]-s[j])%T+F[j];
		add(root,0,T,((-s[i])%T+T)%T,i);
	}
}

void work()
{
	int Test;
	cin>>Test;
	while (Test--)
	{
		int Time;
		scanf("%d",&Time);
		int L=((g-s[0]-Time)%T+T)%T,R=((-s[0]-Time)%T+T)%T;
		int j=(L<R)?get(root,0,T,L,R):min(get(root,0,T,0,R),get(root,0,T,L,T));
		if (j==INF)
			printf("%I64d\n",Time+s[0]);
		else
			printf("%I64d\n",Time+s[0]-s[j]+T-(Time+s[0]-s[j])%T+F[j]);
	}
}

int main()
{
	init();
	work();
	return 0;
}