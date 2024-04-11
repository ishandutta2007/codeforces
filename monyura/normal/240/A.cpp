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
typedef pair<ll,int> pli;

const double PI=acos(-1.0);


void run()
{
	int n,k;
	cin>>n>>k;
	bool Fav[200]={0};
	rep(i,0,k)
	{
		int a;
		scanf("%d",&a);
		Fav[a]=1;
	}
	int t;
	cin>>t;
	char str[100];
	int max_pot=0;
	int max_fav=0;
	int P[200];
	int F[200];
	rep(i,0,t)
	{
		int d;
		scanf("%s%d",str,&d);
		int fav_cnt=0;
		int zero=0;
		rep(j,0,d)
		{
			int a;
			scanf("%d",&a);
			if (Fav[a])
				++fav_cnt;
			if (a==0)
				++zero;
		}
		int left=n-d+zero;
		int fav_left=k-fav_cnt;
		int add=min(max(0,fav_left - (left-zero)),zero);
		int pot = fav_cnt + min(zero,fav_left);
		fav_cnt+=add;
		max_pot=max(pot,max_pot);
		max_fav=max(fav_cnt,max_fav);
		P[i]=pot;
		F[i]=fav_cnt;
	}
	rep(i,0,t)
	{
		int res=2;
		bool ok=1;
		rep(j,0,t)
			if (i!=j && F[i]<P[j])
				 ok=0;
		if (ok)
			res=0;
		ok=0;
		rep(j,0,t)
			if (i!=j && P[i]<F[j])
				 ok=1;
		if (ok)
			res=1;
		printf("%d\n",res);
	}


}


int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
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