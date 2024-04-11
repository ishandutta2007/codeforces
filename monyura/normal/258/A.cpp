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


ll toPow(ll a,ll b,ll mod)
{
	a%=mod;
	if (a<0) a+=mod;
	ll res=1;
	while (b)
	{
		if (b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

void build74(int n,vector<ll> &v)
{
	rep(i,0,1<<n)
	{
		ll mn=1;
		ll curr=0;
		rep(j,0,n)
		{
			curr+=mn * ((i>>j)&1 ? 7: 4);
			mn*=10;
		}
		v.push_back(curr);
	}
}

void run()
{	
	char str[100100];
	scanf("%s",str);
	char *ans=str;
	while (*ans=='1') 
		++ans;
	if (*ans==0)
		printf("%s",str+1);
	else
	{
		*ans=0;
		printf("%s",str);
		printf("%s",ans+1);
	}
	puts("");
}


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("barns.in","r",stdin);
	//freopen("barns.out","w",stdout);
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