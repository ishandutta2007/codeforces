//#pragma comment(linker,"/STACK:128000000")
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

typedef vector<int> vi;
vi g[500100];
int pred[500100];
vi Ans[500100];

int findPred(int a)
{
	if (pred[a]!=a)
		pred[a]=findPred(pred[a]);
	return pred[a];
}
int P[500100]={0};
void run()
{
	int n,m;
	cin>>n>>m;
	
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int minSt=0;
	rep(i,0,n)
		if (g[i].size()<g[minSt].size())
			minSt=i;
	int p=0;
	vector<int> vec;
	rep(i,0,n)
		pred[i]=i;
	rep(i,0,n)
		sort(all(g[i]));
	vec.push_back(minSt);
	int cnt=0;
	rep(i,0,n)
		if (p<g[minSt].size() && g[minSt][p]==i)
		{
			vec.push_back(i);
			p++;
		}
		else
		{
			cnt++;
			pred[i]=minSt;
			rep(j,0,g[i].size())
				P[g[i][j]]++;
		}
	g[minSt].clear();
	rep(i,0,n)
		if (P[i]==cnt)
			g[minSt].push_back(i);
	rep(i,0,vec.size())
		rep(j,0,vec.size())
		if (i!=j && !binary_search(all(g[vec[i]]),vec[j]))
		{
			int pa=findPred(vec[i]);
			int pb=findPred(vec[j]);
			pred[pa]=pb;
		}
	map<int,vi*> mp;
	rep(i,0,n)
	{
		int pr=findPred(i);
		if (mp.find(pr)==mp.end())
			mp[pr]=&Ans[mp.size()];
		mp[pr]->push_back(i);
	}
	printf("%d\n",mp.size());
	rep(i,0,mp.size())
	{
		printf("%d",Ans[i].size());
		rep(j,0,Ans[i].size())
			printf(" %d",Ans[i][j]+1);
		printf("\n");
	}

			
}

int main()
{
#ifdef _MON_JUDGE_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif
	time_t beg=clock();
	run();
#ifdef _MON_JUDGE_
	puts("=================");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/