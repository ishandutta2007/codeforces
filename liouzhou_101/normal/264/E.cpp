#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=1<<18;

struct segment_tree
{
	int v[MaxN<<1];
	void add(int x,int y)
	{
		int k=x+MaxN-1;
		v[k]=y;
		for (k>>=1;k;k>>=1)
			v[k]=max(v[k<<1],v[k<<1|1]);
	}
	int get(int k,int L,int R,int x,int y)
	{
		if (L==x&&R==y) return v[k];
		int m=(L+R)>>1;
		if (y<=m) return get(k<<1,L,m,x,y);
		if (x>m) return get(k<<1|1,m+1,R,x,y);
		return max(get(k<<1,L,m,x,m),get(k<<1|1,m+1,R,m+1,y));
	}
	int get(int x,int y)
	{
		return get(1,1,MaxN,x,y);
	}
}Tx,Ty;

set<int> sx,sy;
int ytox[MaxN],xtoy[MaxN];

void add(int x,int y)
{
	sx.insert(x);
	sy.insert(y);
	xtoy[x]=y;
	ytox[y]=x;
	vector<pii> v;
	for (set<int>::iterator it=sy.begin();it!=sy.end();++it)
	{
		v.push_back(pii(ytox[*it],*it));
		Tx.add(ytox[*it],0);
		Ty.add(*it,0);
		if (*it==y) break;
	}
	for (vector<pii>::reverse_iterator it=v.rbegin();it!=v.rend();++it)
	{
		int tmp=Tx.get(it->X,MaxN)+1;
		Tx.add(it->X,tmp);
		Ty.add(it->Y,tmp);
	}
}

void del(int k)
{
	vector<pii> v;
	for (set<int>::iterator it=sx.begin();it!=sx.end();++it)
	{
		v.push_back(pii(*it,xtoy[*it]));
		Tx.add(*it,0);
		Ty.add(xtoy[*it],0);
		if (!--k)
		{
			sy.erase(xtoy[*it]);
			sx.erase(it);
			break;
		}
	}
	int flag=0;
	for (vector<pii>::reverse_iterator it=v.rbegin();it!=v.rend();++it)
	{
		int tmp=0;
		if (flag) tmp=Ty.get(it->Y,MaxN)+1;
		flag=1;
		Tx.add(it->X,tmp);
		Ty.add(it->Y,tmp);
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		int t,x;
		scanf("%d%d",&t,&x);
		if (t==1)
		{
			int y;
			scanf("%d",&y);
			add(x,y-i+m);
		}
		else
		{
			del(x);
		}
		printf("%d\n",Tx.get(1,MaxN));
	}
	return 0;
}