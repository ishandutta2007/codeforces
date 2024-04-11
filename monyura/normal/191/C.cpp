#pragma comment(linker,"/STACK:128000000")
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

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

set<int> BUFF[100100];
int pos=0;
struct vert
{
	vector<int> inc;
	vector<int> ind;
	vector<int> who;
	bool was;
	set<int> *curr;
	vert()
	{
		was=0;
		curr=0;
	}
} g[100100];

int Ans[100100];
typedef set<int>::iterator iter;
void dfs(int k)
{
	g[k].was=true;
	set<int>* pntr;
	rep(i,0,g[k].inc.size())
		if (!g[g[k].inc[i]].was)
		{
			dfs(g[k].inc[i]);
			pntr=g[g[k].inc[i]].curr;
			Ans[g[k].ind[i]]=pntr->size();
			if (g[k].curr==0) g[k].curr=pntr;
			else
			{
				if (g[k].curr->size()<pntr->size())
					swap(g[k].curr,pntr);
				for (iter i=pntr->begin();i!=pntr->end();i++)
					if (g[k].curr->find(*i)!=g[k].curr->end())
						g[k].curr->erase(*i);
					else
						g[k].curr->insert(*i);
			}
		}
	if (g[k].curr==0)
		g[k].curr=BUFF+pos++;
	rep(i,0,g[k].who.size())
	{
		int w=g[k].who[i];
		if (g[k].curr->find(w)!=g[k].curr->end())
			g[k].curr->erase(w);
		else
			g[k].curr->insert(w);
	}

}

void run()
{
	int n;
	cin>>n;
	rep(i,0,n-1)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].inc.push_back(b);
		g[a].ind.push_back(i);
		g[b].inc.push_back(a);
		g[b].ind.push_back(i);
	}
	int k;
	cin>>k;
	rep(i,0,k)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].who.push_back(i);
		g[b].who.push_back(i);
	}
	dfs(0);
	rep(i,0,n-1)
		printf("%d ",Ans[i]);
	printf("\n");
}

int main()
{
#ifdef _MONYURA_
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
//#else
//		freopen(F_NAME".in","r",stdin);
//		freopen(F_NAME".out","w",stdout);
#endif
	time_t beg=clock();
	run();
	fprintf(stderr,"Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
	return 0;
}

/*

*/