//#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
//#endif

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


void run()
{
	int n;
	cin>>n;
	vector<int> vec;
	vector<int> A;
	vec.push_back(0);
	A.push_back(0);
	ll sum = 0;
	rep(i,0,n)
	{
		int t;
		cin>>t;
		if (t==1)
		{
			int a,x;
			scanf("%d%d",&a,&x);
			if (a>vec.size())
				a=vec.size();
			sum+=a*ll(x);
			vec[a-1]+=x;
		}
		else if (t==2)
		{
			int k;
			scanf("%d",&k);
			vec.push_back(0);
			A.push_back(k);
			sum+=k;
		}
		else
		{
			sum-=vec.back();
			sum-=A.back();
			vec[vec.size()-2]+=vec.back();
			vec.pop_back();
			A.pop_back();
		}
		printf("%.8lf\n",double(sum)/vec.size());
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
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
3
abcdefghABCDEFGH
3
abc
a
abAB
xyz
1
xyz
abacaba
6
a
aba
caba 
acaba
ba
bacb
*/