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


int mod=1e9+7;


ll toPow(ll a,int b)
{
	a%=mod;
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

ll getRev(int a,int mod)
{
	ll res=toPow(a,mod-2);
	return res;
}

void BF(int *A,int n,int k)
{
	rep(i,0,k)
	{
		rep(j,1,n)
			A[j]=(A[j-1]+A[j])%mod;
	}
}

void run()
{
	int n,k;
	int A[2001];
	cin>>n>>k;
	rep(i,0,n)
		scanf("%d",A+i);
	ll C[2010]={1};
	if (k!=0)
	{
		rep(i,1,n+1)
		{
			C[i]=(C[i-1]*(i+k-1)%mod)*getRev(i,mod)%mod;
		}
	}
	int B[2010];
	rep(i,0,n)
	{
		ll curr=0;
		rep(j,0,i+1)
			curr+=(C[j]*A[i-j])%mod;
		curr%=mod;
		int a=curr;
		B[i]=a;
		printf("%d ",a);
	}
	puts("");
	/*BF(A,n,k);
	rep(i,0,n)
		if (B[i]!=A[i])
			puts("FAIL!");*/
	
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