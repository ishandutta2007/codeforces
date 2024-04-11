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

void run()
{
	int n,m;
	cin>>n>>m;
	int R[1001]={0},C[1001]={0};
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		R[a] = C[b] = 1;
	}
	int res = 0;
	rep(i,1,n/2)
	{
		int mx = 0;
		rep(j,0,1<<8)
		{
			bool stop = false;
			rep(k,0,4)
				if (((j>>(2*k))&3)==3)
				{
					stop = true;
					break;
				}
			if (stop) 
				continue;
			bool B[8];
			rep(k,0,8)
				B[k]=(j>>k)&1;
			if (B[0] && B[4] || B[2] && B[5] || B[7] && B[3] || B[1] && B[6])
				continue;
			int curr = 0;
			bool Can[4]={!C[i],!C[n-1-i],!R[i],!R[n-1-i]};
			rep(k,0,8)
				if (((j>>k)&1) && Can[k/2])
					++curr;
			mx=max(curr,mx);
		}
		res+=mx;
	}
	if (n&1)
		res += R[n/2]==0 || C[n/2]==0;
	cout<<res<<endl;
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