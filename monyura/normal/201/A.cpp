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
	int x;
	cin>>x;
	if (x==1)
	{
		printf("1\n");
		return;
	}
	if (x==3)
	{
		printf("5\n");
		return;
	}
	rep(n,3,300)
	{
		if ((n&1)==0)
		{
			int cnt=(SQR(n/2-1)+1)/2*4;
			if (cnt>=x && (cnt-x)%4==0)
			{
				printf("%d\n",n);
				break;
			}
		}
		else
		{
			int cnt=(SQR(n/2)+1)/2*4+(n/2)/2*4+1;
			if (cnt>=x)
			{
				printf("%d\n",n);
				break;
			}
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