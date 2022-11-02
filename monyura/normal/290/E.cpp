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

ll gcd(ll a,ll b)
{
	while (b)
	{
		int c = b;
		b = a % b;
		a = c;
	}
	return a;
}

void run()
{
	char str[1001000];
	gets(str);
	int HW = strlen("Hello, world!");
	int hcnt = count(str,str+strlen(str),'H');
	int qcnt = count(str,str+strlen(str),'Q');
	int q = -1;
	rep(i,0,1001)
		if (i*i==qcnt)
			q=i;
	if (q==-1)
	{
		puts("No");
		return;
	}
	if (q==0)
	{
		puts("Yes");
		return;
	}
	int n = strlen(str);
	if (hcnt % (q+1)!=0)
	{
		puts("No");
		return;
	}
	int h = hcnt/(q+1);
	int a = 0;
	int b = 0;
	int has = 0;
	rep(i,0,strlen(str))
		if (str[i]=='Q')
		{
			++has;
			if (has==1)
				a=i;
			if (has==q)
				b=i;
		}
	int cnt = 0;
	for (int i=0;str[i]=='H';++i)
		++cnt;
	if (cnt&1)
	{
		puts("No");
		return;
	}
	int cnt2 =0;
	for (int i=n-1;str[i]=='H';--i)
		++cnt2;
	if (cnt2&1)
	{
		puts("No");
		return;
	}
	cnt>>=1;
	cnt2>>=1;
	char S[1010000]={0};
	int p = 0;
	rep(i,0,cnt)
		S[p++]='H';
	rep(i,a,b+1)
		S[p++]=str[i];
	rep(i,0,cnt2)
		S[p++]='H';
	char A[10000000]={0};
	rep(i,0,p)
		if (S[i]=='H')
			strcat(A,"H");
		else
			strcat(A,S);
	if (count(S,S+p,'H')!=h)
	{
		puts("No");
		return;
	}
	puts(strcmp(A,str)==0?"Yes":"No");
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