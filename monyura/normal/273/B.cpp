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
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


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

const double PI=acos(-1.0);
const int SZ=200100;
int del[SZ];
int pr[SZ];
int prCnt=0;
int step[SZ]={0};

void init()
{
	rep(i,2,SZ+1)
	{
		if (del[i]==0)
		{
			pr[prCnt++]=i;
			del[i]=i;
		}
		for (int j=0;j<prCnt && pr[j]<=del[i] && ll(pr[j])*i<=SZ;j++)
			del[pr[j]*i] = pr[j];
	}
}

int toPow(ll a,int b,int m)
{
	int res=1;
	while (b)
	{
		if (b&1)
			res=(res*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return res;
}

int calc(int n,int k,int m)
{
	ll res=1;
	rep(i,2,n+1)
	{
		int curr=i;
		while ((curr&1)==0 && k>0)
		{
			curr>>=1;
			k--;
		}
		res=(res*curr)%m;
	}
	return res;
}

void run()
{
	int n;
	cin>>n;
	pii A[200100];
	rep(t,0,2)
		rep(i,0,n)
		{
			scanf("%d",&A[i+t*n].first);
			A[i+t*n].second=i;
		}
	int m;
	cin>>m;
	sort(A,A+2*n);
	ll res=1;
	for (int i=0;i<2*n;)
	{
		int j=i;
		int same = 0;
		while (j<2*n && A[j].first==A[i].first)
		{
			if (j!=0 && A[j]==A[j-1])
				same++;
			j++;
		}
		int curr = calc(j-i,same,m);
		res = (res*curr)%m;
		i=j;
	}
	cout<<res<<endl;
	
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
10 10 92
11 10 92
*/