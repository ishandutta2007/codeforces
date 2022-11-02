#ifdef _MONYURA_
#pragma comment(linker,"/STACK:650000000")
#endif

#include <iostream>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <assert.h>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;



void run()
{
	set<int> x,y;
	set<pii> pnts;
	rep(i,0,8)
	{
		pii p;
		scanf("%d%d",&p.first,&p.second);
		x.insert(p.first);
		y.insert(p.second);
		pnts.insert(p);
	}
	vector<int> vx(all(x)),vy(all(y));
	puts(vx.size()==3 && vy.size()==3 && pnts.size()==8 && pnts.find(pii(vx[1],vy[1]))==pnts.end()
		?"respectable" : "ugly");
}




int main()
{
//#ifdef 
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	time_t st=clock();
//#else
	//freopen(problem".in","r",stdin);
	//freopen(problem".out","w",stdout);
//#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}