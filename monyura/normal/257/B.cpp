#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
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
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double PI=acos(-1.0);

pii getRes(int a,int b)
{
	pii res(0,0);
	int A[200100]={0};
	int Cnt[2]={a-1,b};
	rep(i,1,a+b)
	{
		if (i&1)
		{
			if (Cnt[!A[i-1]])
			{
				A[i]=!A[i-1];
				Cnt[!A[i-1]]--;
			}
			else
			{
				A[i]=A[i-1];
				Cnt[A[i-1]]--;
			}
		}
		else
		{
			if (Cnt[A[i-1]])
			{
				A[i]=A[i-1];
				Cnt[A[i-1]]--;
			}
			else
			{
				A[i]=!A[i-1];
				Cnt[!A[i-1]]--;
			}
		}
	}
	rep(i,1,a+b)
		if (A[i]==A[i-1])
			res.first++;
		else
			res.second++;
	return res;
}

void run()
{
	int a,b;
	cin>>a>>b;
	pii res=max(getRes(a,b),getRes(b,a));
	cout<<res.first<<' '<<res.second<<endl;
}



int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("barns.in","r",stdin);
	//freopen("barns.out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
10 10 92
11 10 92
*/