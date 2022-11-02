#pragma comment(linker,"/STACK:650000000")
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

const double PI = acos(-1.0);

void run()
{
	int a,b;
	cin>>a>>b;
	char str[1000];
	scanf("%s",str);
	int dx = 0,dy = 0;
	char pat[]="UDLR";
	int sX[]={0,0,-1,1};
	int sY[]={1,-1,0,0};
	rep(i,0,strlen(str))
	{
		rep(j,0,4)
			if (pat[j]==str[i])
			{
				dx+=sX[j];
				dy+=sY[j];
			}
	}
	int x=0,y=0;
	if ((dx==0 && dy==0 && x==a && y==b) ||
			(dx==0 && dy!=0 && x==a && (y-b)%dy==0 && (b-y)/dy>=0) ||
			(dx!=0 && dy!=0 && (x-a)%dx==0 && y==b && (a-x)/dx>=0) ||
			(dx!=0 && dy!=0 && (x-a)%dx==0 && (y-b)%dy==0 && (x-a)/dx==(y-b)/dy && (a-x)/dx>=0))

	{
		puts("Yes");
		return;
	}
	rep(i,0,strlen(str))
	{
		rep(j,0,4)
			if (pat[j]==str[i])
			{
				x+=sX[j];
				y+=sY[j];
			}
		if ((dx==0 && dy==0 && x==a && y==b) ||
			(dx==0 && dy!=0 && x==a && (y-b)%dy==0 && (b-y)/dy>=0) ||
			(dx!=0 && dy==0 && (x-a)%dx==0 && y==b && (a-x)/dx>=0) ||
			(dx!=0 && dy!=0 && (x-a)%dx==0 && (y-b)%dy==0 && (x-a)/dx==(y-b)/dy && (a-x)/dx>=0))

		{
			puts("Yes");
			return;
		}
	}
	puts("No");
}

#define problem "proddiff"


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(problem".in","r",stdin);
	//freopen(problem".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}