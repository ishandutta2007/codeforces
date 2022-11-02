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
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;	
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


void run()
{
	int D[27][27][27]={0};
	int n;
	cin>>n;
	char str[100]={0};
	rep(i,0,n)
	{
		scanf("%s",str);
		int m=strlen(str);
		rep(i,0,m)
			D[str[i]-'a'][26][26]=1;
		rep(i,0,m-1)
			D[str[i]-'a'][str[i+1]-'a'][26]=1;
		rep(i,0,m-2)
			D[str[i]-'a'][str[i+1]-'a'][str[i+2]-'a']=1;
	}
	string res;
	rep(i,0,26)
		if (!D[i][26][26])
		{
			printf("%c\n",(char)(i+'a'));
			return;
		}
	rep(i,0,26)
		rep(j,0,26)
			if (!D[i][j][26])
			{
				printf("%c%c\n",(char)(i+'a'),(char)(j+'a'));
				return;
			}
	rep(i,0,26)
		rep(j,0,26)
			rep(k,0,26)
			if (!D[i][j][k])
			{
				printf("%c%c%c\n",char(i+'a'),char(j+'a'),char(k+'a'));
				return;
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
10 10 92
11 10 92
*/