#pragma comment(linker,"/STACK:65000000")
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
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <assert.h>


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
typedef vector<int> vi;

const double PI = acos(-1.0);

const int SZ=10000100;
int primes[1000100];
int pcnt=0;
int del[SZ]={0};

void build()
{
	rep(i,2,SZ)
	{
		if (del[i]==0)
		{
			del[i]=i;
			primes[pcnt++]=i;
		}
		for (int j=0;j<pcnt && primes[j]<=del[i] && ll(primes[j])*i<SZ;++j)
			del[primes[j]*i]=primes[j];
	}
}
ll deg[SZ]={0};
int sum[SZ]={0};
pll Need[1000100];

void run()
{
	build();
	int k;
	cin>>k;
	rep(i,0,k)
	{
		int a;
		scanf("%d",&a);
		sum[a]++;
	}
	int add = 0;
	for (int i=SZ-1;i>=2;--i)
	{
		add+=sum[i];
		if (add)
		{
			int a = i;
			while (a!=1)
			{
				deg[del[a]]+=add;
				a/=del[a];
			}
		}
	}
	int cnt = 0;
	rep(i,0,SZ)
		if (deg[i])
			Need[cnt++]=pll(i,deg[i]);
	ll n = -1;
	ll l = 1, r = 4e18;
	while (l<=r)
	{
		ll c = (l+r)>>1;
		bool ok = true;
		rep(i,0,cnt)
		{
			ll curr = 0,val = 0;
			ll mn = Need[i].first;
			do
			{
				val = c/mn;
				curr += val;
				mn*=Need[i].first;
			}
			while (val>1 && curr<Need[i].second);
			if (curr<Need[i].second)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			r = c-1;
			n = c;
		}
		else
			l = c+1;

	}
	cout<<n<<endl;
}


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(name".in","r",stdin);
	//freopen(name".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
24 54 96 108
*/