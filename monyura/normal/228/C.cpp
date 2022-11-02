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
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bool B[510][510];
bool D[510][510];

int getCnt(char A[510][510],char T[2][2],int n,int m)
{
	rep(i,0,n)
		rep(j,0,m)
		{
			B[i][j]=A[i][j]=='*';
		}
	rep(i,0,n-1)
	{
		rep(j,0,m-1)
		{
			int d=1;
			int b=1;
			rep(x,0,2)
				rep(y,0,2)
				{
					if (A[i+x][j+y]!=T[x][y])
						d=0;
					if (!B[i+x][j+y])
						b=0;
				}
			D[i][j]=d;
			B[i][j]=b;
			
		}
		rep(j,m-1,m)
			D[i][j]=B[i][j]=0;
	}
	rep(i,n-1,n)
		rep(j,m-1,m)
			D[i][j]=B[i][j]=0;
	int res=0;
	for (int sz=2;2*sz<=min(n,m);sz<<=1)
	{
		rep(i,0,n-2*sz+1)
		{
			rep(j,0,m-2*sz+1)
			{
				int d=1;
				int b=1;
				rep(x,0,2)
					rep(y,0,2)
					{
						if (T[x][y]=='*' && !B[i+x*sz][j+y*sz])
							d=0;
						if (T[x][y]=='.' && !D[i+x*sz][j+y*sz])
							d=0;
						if (!B[i+x*sz][j+y*sz])
							b=0;
					}
				res+=d;
				D[i][j]=d;
				B[i][j]=b;
			}
			rep(j,m-2*sz+1,m)
				D[i][j]=B[i][j]=0;
		}
		rep(i,n-2*sz+1,n)
			rep(j,m-2*sz+1,m)
				D[i][j]=B[i][j]=0;

	}
	return res;
}


void run()
{
	int n,m;
	cin>>n>>m;
	char A[510][510];
	rep(i,0,n)
		scanf(" %s",A[i]);
	int res=0;
	rep(i,0,1<<4)
	{
		char T[2][2]={i&1,i&2,i&4,i&8};
		rep(x,0,2)
			rep(y,0,2)
				T[x][y] = T[x][y] ? '*' : '.';
		res+=getCnt(A,T,n,m);
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