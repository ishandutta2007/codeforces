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

int mod;

void mult(int A[2][2],int B[2][2],int Res[2][2])
{
	rep(i,0,2)
		rep(j,0,2)
		{
			ll curr=0;
			rep(k,0,2)
				curr=(curr+A[i][k]*ll(B[k][j]))%mod;
			Res[i][j]=curr;
		}

}

void toPow(int A[2][2],int Res[2][2],ll b,int mod)
{
	rep(i,0,2)
		rep(j,0,2)
			Res[i][j]=i==j;
	int Tmp[2][2];
	while (b)
	{
		if (b&1)
		{
			mult(Res,A,Tmp);
			memcpy(Res,Tmp,sizeof(int)*4);
		}
		mult(A,A,Tmp);
		memcpy(A,Tmp,sizeof(int)*4);
		b>>=1;
	}
}

ll getCnt(ll a,ll b)
{
	if (a<=0) return 0;
	return a/b;
}

ll algo1(ll l,ll r,ll k)
{
	ll res=1;
	int sq=sqrt(double(r-l+1))+10;
	rep(i,1,sq)
	{
		ll here=getCnt(r,i)-getCnt(l-1,i);
		if (here>=k)
			res=i;
	}
	return res;
}

ll algo2(ll l,ll r,ll k)
{
	ll res=1;
	ll sq=sqrt(double(r-l+1))+10;
	rep(val,1,sq)
	{
		rep(j,-1,2)
		{
			ll curr=r/val+j;
			if (curr<=0) curr=1;
			ll here=getCnt(r,curr)-getCnt(l-1,curr);
			if (here>=k)
				res=max(res,curr);
		}
	}
	return res;
}

void run()
{
	cin>>mod;
	ll l,r,k;
	cin>>l>>r>>k;
	ll sq=sqrt(double(r-l+1))+0.05;
	ll res=max(algo1(l,r,k),algo2(l,r,k));
	int A[2][2]={1,1,1,0};
	int Res[2][2];
	if (res<=2)
		printf("%d\n",1%mod);
	else
	{
		toPow(A,Res,res,mod);
		cout<<Res[0][1]%mod<<endl;
	}

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