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

int pr[100100];
int cnt=0;
const int SZ=1e6+100;
int del[SZ];
int Sum[SZ];
void run()
{
	rep(i,2,SZ)
	{
		if (del[i]==0)
		{
			del[i]=i;
			pr[cnt++]=i;
		}
		for (int j=0;j<cnt && pr[j]<=del[i] && ll(pr[j])*i<SZ;j++)
			del[pr[j]*i]=pr[j];
	}
	rep(i,2,SZ)
		Sum[i]=Sum[i-1]+(del[i]==i);
	int a,b,k;
	cin>>a>>b>>k;
	int l=1,r=b-a+1;
	int res=-1;
	while (l<=r)
	{
		int c=(l+r)>>1;
		bool ok=1;
		rep(j,a,b-c+2)
			if (Sum[j+c-1]-Sum[j-1]<k)
			{
				ok=0;
				break;
			}
		if (ok)
		{
			r=c-1;
			res=c;
		}
		else
		{
			l=c+1;
		}
	}
	printf("%d\n",res);
}


int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
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