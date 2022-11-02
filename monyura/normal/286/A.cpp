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

bool isOk(int *p,int n)
{
	rep(i,0,n)
		if (p[p[i]] != n-i-1)
			return false;
	return true;
}


void run()
{
	int p[100100];
	int n;
	cin>>n;
	if (n==1)
	{
		puts("1");
		return;
	}
	if (n%4<=1)
	{
		for (int i=0;i<n/2;i+=2)
		{
			p[i] = i+1;
			p[n-i-1] = n-i-2;
		}
		for (int i=1;i<n/2;i+=2)
		{
			p[i] = n-i;
			p[n-i-1] = i-1;
		}
		if (n%4==1)
			p[n/2] = n/2;
		/*if (!isOk(p,n))
			cerr<<"fail"<<endl;*/
		rep(i,0,n)
			printf("%d ",p[i]+1);
		puts("");
	}
	else
		puts("-1");
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