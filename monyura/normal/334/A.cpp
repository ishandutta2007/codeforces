#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

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

const int SZ=1001;
int Up[SZ][SZ];
bool findRect(bool B[SZ][SZ],int n,int m)
{
	memset(Up,-1,sizeof(Up));
	rep(i,1,n)
		rep(j,0,m)
			if (B[i-1][j]==1)
				Up[i][j] = i-1;
			else
				Up[i][j] = Up[i-1][j];
	rep(i,1,n)
	{
		bool was[SZ] = {0};
		rep(j,0,m)
			if (B[i][j]==1)
			{
				int curr = Up[i][j];
				while (curr!=-1)
				{
					if (was[curr])
						return true;
					was[curr] = 1;
					curr = Up[curr][j];
				}
			}
	}
	return false;
}
int D[3001][3001];
void run()
{
	int n;
	cin>>n;
	rep(i,0,n)
	{
		for (int j=0;j<n/2;j++)
			printf("%d %d ",j*2*n+i+1,(j+1)*2*n-i);
		puts("");
	}
			
}

//#define prob "fibsubseq"

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
    //freopen(prob".in","r",stdin);
    //freopen(prob".out","w",stdout);
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

    return 0;
}