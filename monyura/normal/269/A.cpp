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

const double PI=acos(-1.0);


void run()
{
	int n;
	cin>>n;
	pii A[100100];
	rep(i,0,n)
		scanf("%d%d",&A[i].first,&A[i].second);
	sort(A,A+n);
	rep(i,0,n-1)
	{
		int cnt=A[i].second;
		int k=A[i].first;
		while (cnt>1)
		{
			k++;
			cnt=(cnt>>2) + (cnt%4!=0);
			if (k==A[i+1].first)
			{
				A[i+1].second=max(A[i+1].second,cnt);
				break;
			}
		}
	}
	int res = A[n-1].first;
	int cnt = A[n-1].second;
	if (cnt==1)
		++res;
	while (cnt>1)
	{
		res++;
		cnt=(cnt>>2) + (cnt%4!=0);
	}
	cout<<res<<endl;
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
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
10 10 92
11 10 92
*/