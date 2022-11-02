#pragma comment(linker,"/STACK:16777216")
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
        vector<int> c;
        priority_queue<int,vector<int>,greater<int> > q;
        int h;
        int res;
        int from;
        int fromc;
        vert()
        {
                h=-1;
                res=-1;
        }
} g[5001];

vector<int> por;

void bfs()
{
	queue<int> q;
	q.push(0);
	g[0].h=0;
	while (!q.empty())
	{
		int v=q.front();
		q.pop();
		por.push_back(v);
		rep(i,0,g[v].inc.size())
		{
			if (g[g[v].inc[i]].h==-1)
			{
				g[g[v].inc[i]].h=g[v].h+1;
				q.push(g[v].inc[i]);
			}
		}
	}
}


map<int,int> mp;
void perevesti(int k,int t)
{
        priority_queue<int,vector<int>, greater<int> > &q=g[k].q;
        int to=min(g[k].fromc,int(q.size()));
        rep(i,0,to)
        {
                g[g[k].from].q.push(q.top());
                if (g[k].from==0) mp[q.top()]=t;
                q.pop();
        }
}

int main()
{
        int n;
        cin>>n;
        int A[5001];
        rep(i,0,n)
        {
                scanf("%d",A+i);
                g[i].q.push(A[i]);
        }
        rep(i,0,n-1)
        {
                int c,u,v;
                scanf("%d%d%d",&v,&u,&c);
                u--;v--;
                g[u].inc.push_back(v);
                g[v].inc.push_back(u);
                g[u].c.push_back(c);
                g[v].c.push_back(c);
        }
        //dfs(0,0);
		bfs();
        int res=0;
        mp[A[0]]=0;
        rep(i,1,n)
                rep(j,0,g[i].inc.size())
                if (g[g[i].inc[j]].h<g[i].h)
                {
                        g[i].from=g[i].inc[j];
                        g[i].fromc=g[i].c[j];
                }
        int as=1;
        while (g[0].q.size()!=n)
        {
                res++;
				rep(i,1,n)
                        perevesti(por[i],res);
        }
        rep(i,0,n)
                printf("%d ",mp[A[i]]);
        return 0;
}