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

int gcd(int a,int b)
{
	int c=a;
	while (b)
	{
		c=b;
		b=a%b;
		a=c;
	}
	return c;
}

int nok(int a,int b)
{
	return a/gcd(a,b)*b;
}

void run()
{
	ll a,b;
	int k;
	cin>>a>>b;
	cin>>k;
	if (a==b)
	{
		puts("0");
		return;
	}
	int nk = 1;
	rep(i,2,k+1)
	{
		nk=nok(nk,i);
	}
	int D[370000]={0};
	rep(i,1,nk)
	{
		D[i]=D[i-1];
		rep(j,2,k+1)
			if (D[i]>D[i - i%j])
				D[i]=D[i - i%j];
		++D[i];
	}
	ll res=0;
	ll pa=a/nk;
	ll pb=b/nk;
	if (pa!=pb)
	{
		res+=(pa-pb-1)*(D[nk-1]+1);
		res+=D[a%nk]+1;
		b%=nk;
		D[b]=0;
		rep(i,b+1,nk)
		{
			D[i]=D[i-1];
			rep(j,2,k+1)
			{
				int to = i - i%j;
				if (to>=b && D[i]>D[to])
					D[i]=D[to];
			}
			++D[i];
		}
		res+=D[nk-1];
	}
	else
	{
		b%=nk;
		a%=nk;
		D[b]=0;
		rep(i,b+1,a+1)
		{
			D[i]=D[i-1];
			rep(j,2,k+1)
			{
				int to = i - i%j;
				if (to>=b && D[i]>D[to])
					D[i]=D[to];
			}
			++D[i];
		}
		res=D[a];
	}
	cout<<res<<endl;
	//cerr<<nk<<endl;
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
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
10 10 10 10 1 1
2 2 1 1 1 2
5 5 3 3  5 5
6 6 1 1 1 1
*/