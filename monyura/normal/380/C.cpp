#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <iomanip>
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
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

const double PI = acos(-1.0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<double,int> pdi;
typedef pair<int,double> pid;

char str[1000100];

struct query
{
	int l,r,ind;
	bool operator<(const query &other) const
	{
		return r < other.r;
	}
};

int Fen[1000100] = {0};
void addFen(int pos, int val)
{
	++pos;
	for (int i = pos; i < 1000100; i+=i&-i)
		Fen[i] += val;
}

int getFen(int pos)
{
	int res = 0;
	++pos;
	for (int i = pos; i>0; i-= i&-i)
		res += Fen[i];
	return res;
}

void run()
{
	scanf("%s",str);
	int n = strlen(str);
	int m;
	cin>>m;
	query Q[100100];
	rep(i,0,m)
	{
		scanf("%d%d",&Q[i].l, &Q[i].r);
		--Q[i].l; --Q[i].r;
		Q[i].ind = i;
	}
	sort(Q,Q+m);
	vector<int> open;
	int pos = 0;
	int Res[100100];
	int total = 0;
	rep(i,0,n)
	{
		if (str[i] == ')')
		{
			if (open.size() > 0)
			{
				++total;
				addFen(open.back(), 1);
				open.pop_back();
			}
		}
		else
			open.push_back(i);
		while (pos < m && Q[pos].r == i)
		{
			int res = total - getFen(Q[pos].l-1);
			Res[Q[pos].ind] = res;
			++pos;
		}
	}
	rep(i,0,m)
		printf("%d\n", 2*Res[i]);
	
}	


//#define prob "xoring"


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	#ifdef prob
		freopen(prob".in","r",stdin);
		freopen(prob".out","w",stdout);
	#endif
#endif
	run();
#ifdef _MONYURA_
	printf( "\n=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}