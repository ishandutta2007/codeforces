#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

void run()
{
	int A[1001][1001];
	int n,m,k;
	cin>>n>>m>>k;
	rep(i,0,n)
		rep(j,0,m)
		scanf("%d",&A[i][j]);
	int Row[1001],Col[1001];
	rep(i,0,n)
		Row[i]=i;
	rep(j,0,m)
		Col[j]=j;
	char str[10];
	rep(i,0,k)
	{
		int x,y;
		scanf(" %s%d%d",str,&x,&y);
		--x;--y;
		if (*str=='c')
			swap(Col[x],Col[y]);
		else if (*str=='r')
			swap(Row[x],Row[y]);
		else
		{
			int res=A[Row[x]][Col[y]];
			printf("%d\n",res);
		}

	}
	
}

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t beg=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("================\n");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/