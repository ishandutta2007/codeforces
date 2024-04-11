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

const int SZ=1002000;
int pr[100100];
int del[SZ];
int cnt=0;

ll gcd(ll a,ll b)
{
	ll c=a;
	while (b)
	{
		c=b;
		b=a%b;
		a=c;
	}
	return c;
}

ll nok(ll a,ll b)
{
	return ll(a)/gcd(a,b)*b;
}

void test(int n)
{
	int R[5]={0,1,2,6,12};
	int A[3]={0};
	ll res=1;
	ll res2=1;
	if (n<=4)
	{
		res=R[n];
	}
	else
	{
		rep(i,max(n-100,1),n+1)
			rep(j,i+1,n+1)
				rep(k,j+1,n+1)
				{
					ll curr=nok(i,nok(j,k));
					if (curr>res)
						res=curr;
				}
		/*rep(i,1,n+1)
			rep(j,i+1,n+1)
				rep(k,j+1,n+1)
			{
				ll curr=nok(i,nok(j,k));
				if (curr>res)
				{
					fprintf(stderr,"%d) res=%lld %d %d %d %lld\n",n,res,i,j,k,curr);
				}
			}*/
	}
	/*printf("%d) ",n);
	if (res2>res)
		puts("fail");
	cout<<res<<' '<<res2<<endl;*/
	cout<<res<<endl;
}

void run()
{
	int n;
	cin>>n;
	test(n);
	/*rep(i,2,SZ)
	{
		if (del[i]==0)
		{
			del[i]=i;
			pr[cnt++]=i;
		}
		for (int j=0;j<cnt && pr[j]<=del[i] && ll(i)*pr[j]<SZ;j++)
			del[i*pr[j]]=pr[j];
	}*/
	
	/*rep(i,4,1000)
	{
		fprintf(stderr,"%d\n",i);
		test(i);
	}*/
	
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