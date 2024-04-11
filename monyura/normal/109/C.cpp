#pragma comment(linker,"/STACK:64000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

struct vert
{
	bool was;
	int tut;
	vector<int> inc;
	vector<ll> cnt;
	vert()
	{
		was=0;
		tut=0;
	}
} *g;

bool isLuck(int v)
{
	while (v)
	{
		if (v%10!=4 && v%10!=7) return false;
		v/=10;
	}
	return true;
}

ll gCnt=0;
int gN;

ll dfs(int k)
{
	g[k].was=1;
	ll sum=0;
	ll curr,lft;
	rep(i,0,g[k].inc.size())
		if (!g[g[k].inc[i]].was)
		{
			curr=dfs(g[k].inc[i]);
			if (curr>=2) gCnt+=curr*(curr-1)*g[k].tut;
			/*lft=gN-curr;
			if (curr>=2) gCnt+=curr*(curr-1)*lft;
			if (lft>=2) gCnt+=lft*(lft-1)*curr;*/
			sum+=curr;
			g[k].cnt.push_back(curr);
		}
	curr=gN-sum-g[k].tut;
	if (curr>=2) gCnt+=curr*(curr-1)*g[k].tut;
	g[k].cnt.push_back(curr);
	sum+=curr;
	lft=0;
	rep(i,0,g[k].cnt.size())
		lft+=g[k].cnt[i]*(sum-g[k].cnt[i]);
	gCnt+=lft*g[k].tut;
	return gN-g[k].cnt.back();
}

int *pred;
int *sz;

int find(int a)
{
	if (pred[a]!=a) 
		pred[a]=find(pred[a]);
	return pred[a];
}



int main()
{
	int n;
	cin>>n;
	pred=new int[n];
	sz=new int[n];
	g=new vert[n];
	gN=n;
	rep(i,0,n)
	{
		pred[i]=i;
		sz[i]=1;
	}
	vector<pii> vec;
	rep(i,0,n-1)
	{
		int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		a--;
		b--;
		bool L=isLuck(v);
		if (L) vec.push_back(pii(a,b));
		else
		{
			int pa=find(a);
			int pb=find(b);
			pred[pa]=pb;
			sz[pb]+=sz[pa];
		}
	}
	int st=0;
	rep(i,0,vec.size())
	{
		int a=find(vec[i].first);
		int b=find(vec[i].second);
		st=a;
		g[a].inc.push_back(b);
		g[b].inc.push_back(a);
		g[a].tut=sz[a];
		g[b].tut=sz[b];
	}
	gCnt=0;
	dfs(st);
	cout<<gCnt<<endl;
	return 0;
}

/*
7
1 3 0
2 3 0
3 4 4
4 7 4
4 6 7
5 6 0
*/