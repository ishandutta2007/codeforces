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
const int MOD=777777777;

int n,m;
int c[4][4];

struct node
{
	node *Lc,*Rc;
	int L,R,mid;
	int v[4][4];
};

int a[MaxN];

struct segment_tree
{
	int tot;
	node tree[MaxN*2];
	node *root;
	void update(node *it)
	{
		for (int i=1;i<=3;++i)
			for (int j=1;j<=3;++j)
				it->v[i][j]=0;
		for (int i=1;i<=3;++i)
			for (int j=1;j<=3;++j)
				if (c[i][j])
					for (int x=1;x<=3;++x)
						for (int y=1;y<=3;++y)
						{
							it->v[x][y]+=(long long)it->Lc->v[x][i]*it->Rc->v[j][y]%MOD;
							if (it->v[x][y]>=MOD) it->v[x][y]-=MOD;
						}
	}
	node *build(int L,int R)
	{
		node *it=&tree[++tot];
		it->L=L;
		it->R=R;
		if (L==R)
		{
			for (int i=1;i<=3;++i)
				it->v[i][i]=1;
		}
		else
		{
			it->mid=(L+R)>>1;
			it->Lc=build(L,it->mid);
			it->Rc=build(it->mid+1,R);
			update(it);
		}
		return it;
	}
	void build()
	{
		root=build(1,n);
	}
	void rebuild(node *it,int x)
	{
		if (it->L==it->R)
		{
			for (int i=1;i<=3;++i)
				for (int j=1;j<=3;++j)
					it->v[i][j]=0;
			if (a[x]==0)
			{
				for (int i=1;i<=3;++i)
					it->v[i][i]=1;
			}
			else
			{
				it->v[a[x]][a[x]]=1;
			}
			return;
		}
		if (x<=it->mid)
			rebuild(it->Lc,x);
		else
			rebuild(it->Rc,x);
		update(it);
	}
	void change(int x,int y)
	{
		a[x]=y;
		rebuild(root,x);
		int ans=0;
		for (int i=1;i<=3;++i)
			for (int j=1;j<=3;++j)
			{
				ans+=root->v[i][j];
				if (ans>=MOD) ans-=MOD;
			}
		printf("%d\n",ans);
	}
}T;

int main()
{
	cin>>n>>m;
	for (int i=1;i<=3;++i)
		for (int j=1;j<=3;++j)
			cin>>c[i][j];
	T.build();
	while (m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		T.change(x,y);
	}
	return 0;
}