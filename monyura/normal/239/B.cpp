#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
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
#include <cmath>
#include <queue>
#include <ctime>


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

void go(char *str,int l,int r,int R[10])
{
	rep(i,0,10)
		R[i]=0;
	char A[102];
	strncpy(A,str+l,r-l+1);
	int cp=0;
	int dp=1;
	int n=r-l+1;
	A[n]=0;
	int pr=n;
	while (cp>=0 && cp<n)
	{
		int i=cp;
		if ((A[i]=='<' || A[i]=='>') && (A[pr]=='<' || A[pr]=='>'))
			A[pr]='-';
		if (A[i]=='<')
		{
			dp=-1;
			pr=cp;
		}
		if (A[i]=='>')
		{
			dp=1;
			pr=cp;
		}
		if (A[i]>='0' && A[i]<='9')
		{
			R[A[i]-'0']++;
			pr=cp;
			if (A[i]=='0')
				A[i]='-';
			else
				--A[i];
		}
		cp+=dp;
	}
}

void run()
{
	char str[1001];
	int n,k;
	scanf("%d%d%s",&n,&k,str);
	rep(i,0,k)
	{
		int R[10];
		int l,r;
		scanf("%d%d",&l,&r);
		--l;--r;
		go(str,l,r,R);
		rep(j,0,10)
			printf("%d ",R[j]);
		puts("");
	}
}


int main()
{
	srand(time(0));
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("final.in","r",stdin);
	//freopen("final.out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*

*/