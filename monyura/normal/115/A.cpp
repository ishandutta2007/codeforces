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

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

struct vert
{
	vector<int> inc;
	bool was;
	int h;
	vert()
	{
		was=0;
	}
} *g;
int cnt;
void dfs(int k)
{
	g[k].was=1;
	rep(i,0,g[k].inc.size())
		if (!g[g[k].inc[i]].was)
		{
			g[g[k].inc[i]].h=g[k].h+1;
			dfs(g[k].inc[i]);
		}
	cnt=max(cnt,g[k].h);
}

int main()
{
	int n;
	cin>>n;
	g=new vert[n];
	vector<int> s;
	rep(i,0,n)
	{
		int a;
		scanf("%d",&a);
		if (a!=-1)
		{
			a--;
			g[a].inc.push_back(i);
			g[i].inc.push_back(a);
		}
		else
			s.push_back(i);
	}
	int res=1;
	rep(i,0,s.size())
	{
		cnt=1;
		g[s[i]].h=1;
		dfs(s[i]);
		res=max(res,cnt);
	}
	cout<<res<<endl;
	return 0;
}


/*

*/