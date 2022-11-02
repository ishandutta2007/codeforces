

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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double PI = acos(-1.0);

struct position
{
	int ones;
	int two;
	int boat;
	position(){}
	position(int ones0,int two0,int boat0)
	{
		ones = ones0;
		two = two0;
		boat = boat0;
	}
};

struct vert
{
	vector<position> from;
	ll dyn;
	int h;
	bool was;
	vert()
	{
		was = 0;
		h=-1;
		dyn=0;
	}
} g[52][52][2];

int One,Two;
void bfs(int one,int two,int k)
{
	queue<position> q;
	q.push(position(one,two,0));
	g[one][two][0].h = 0;
	g[one][two][0].dyn = 1;
	position nxt,pos;
	while (!q.empty())
	{
		pos = q.front();
		q.pop();
		int toOne = pos.boat == 0 ? pos.ones : One - pos.ones;
		int toTwo = pos.boat == 0? pos.two : Two - pos.two;
		rep(i,0,toOne+1)
		{
			if (i>k) break;
			rep(j,i==0,toTwo+1)
			{
				if (i+2*j>k) break;
				int nxtOne = pos.boat==0 ? pos.ones - i : pos.ones + i;
				int nxtTwo = pos.boat==0 ? pos.two - j : pos.two + j;
				if (g[nxtOne][nxtTwo][pos.boat^1].h==-1)
				{
					g[nxtOne][nxtTwo][pos.boat^1].h = g[pos.ones][pos.two][pos.boat].h  + 1;
					q.push(position(nxtOne,nxtTwo,pos.boat^1));
				}
				if (g[nxtOne][nxtTwo][pos.boat^1].h==g[pos.ones][pos.two][pos.boat].h + 1)
				{
					g[nxtOne][nxtTwo][pos.boat^1].from.push_back(pos);
				}
			}
		}
	}
}
const int mod = 1e9 + 7;
ll C[52][52]={0};
void fillC()
{
	rep(i,0,52)
		C[i][0] = 1;
	rep(i,1,52)
		rep(j,1,52)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
}


void dfs(int one,int two,int boat)
{
	g[one][two][boat].was = true;
	rep(i,0,g[one][two][boat].from.size())
	{
		position nxt = g[one][two][boat].from[i];
		if (!g[nxt.ones][nxt.two][nxt.boat].was)
			dfs(nxt.ones,nxt.two,nxt.boat);
		int dOne = abs(one - nxt.ones);
		int dTwo = abs(two - nxt.two);
		ll mul = C[nxt.ones][dOne] * C[nxt.two][dTwo] % mod;
		if (boat==0)
			mul = C[One - nxt.ones][dOne]*C[Two - nxt.two][dTwo] % mod;
		g[one][two][boat].dyn = (g[one][two][boat].dyn + mul * g[nxt.ones][nxt.two][nxt.boat].dyn) % mod;
	}
}

void run()
{
	fillC();
	int n,k;
	int A[52];
	int Cnt[2]={0};
	cin>>n>>k;
	k/=50;
	rep(i,0,n)
	{
		int a;
		scanf("%d",&a);
		Cnt[a/50-1]++;
	}
	One = Cnt[0];
	Two = Cnt[1];
	bfs(Cnt[0],Cnt[1],k);
	dfs(0,0,1);
	int can = g[0][0][1].h;
	if (can==-1)
	{
		puts("-1\n0\n");
	}
	else
	{
		int res = g[0][0][1].dyn;
		printf("%d\n%d\n",can,res);
	}
}

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
#endif
    run();
#ifdef _MONYURA_
    printf( "=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

    return 0;
}