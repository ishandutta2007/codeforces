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

const double PI = acos(-1.0);

int L[100100],R[100100],D[100100];
ll Cnt[100100]={0};

void run()
{
    int n,m,k;
	cin>>n>>m>>k;
	ll A[100100];
	rep(i,0,n)
	{
		int a;
		scanf("%d",&a);
		A[i]=a;
	}
	rep(i,0,m)
	{
		scanf("%d%d%d",L+i,R+i,D+i);
		--L[i];
		--R[i];
	}
	rep(i,0,k)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		--x;--y;
		Cnt[x]++;
		Cnt[y+1]--;
	}
	ll curr = 0;
	ll S[100100]={0};
	rep(i,0,m)
	{
		curr+=Cnt[i];
		ll val = curr * D[i];
		S[L[i]]+=val;
		S[R[i]+1]-=val;
	}
	ll sum = 0;
	rep(i,0,n)
	{
		sum+=S[i];
		A[i]+=sum;
	}
	rep(i,0,n)
		printf("%I64d ",A[i]);
	puts("");
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