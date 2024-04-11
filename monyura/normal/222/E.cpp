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

const int SZ=52;
const int MOD=1000000007;
void mult(int A[SZ][SZ],int B[SZ][SZ],int C[SZ][SZ],int m)
{
	rep(i,0,m)
		rep(j,0,m)
		{
			ll curr=0;
			rep(k,0,m)
				curr+=ll(A[i][k])*B[k][j]%MOD;
			C[i][j]=curr%MOD;
		}
}

void toPow(int A[SZ][SZ],int Res[SZ][SZ],ll b,int m)
{
	int M[SZ][SZ];
	memcpy(M,A,sizeof(int)*SZ*SZ);
	rep(i,0,m)
		rep(j,0,m)
			Res[i][j]=i==j;
	int T[SZ][SZ];
	while (b)
	{
		if (b&1)
		{
			mult(Res,M,T,m);
			memcpy(Res,T,sizeof(int)*SZ*SZ);
		}
		mult(M,M,T,m);
		memcpy(M,T,sizeof(int)*SZ*SZ);
		b>>=1;
	}
}

void run()
{
	int A[SZ][SZ];
	rep(i,0,SZ)
		rep(j,0,SZ)
			A[i][j]=1;
	ll n;
	int m,k;
	cin>>n>>m>>k;
	char str[10];
	rep(i,0,k)
	{
		scanf("%s",str);
		int ind[2];
		rep(j,0,2)
		{
			if (str[j]>='a' && str[j]<='z')
				ind[j]=str[j]-'a';
			else
				ind[j]=str[j]-'A'+26;
		}
		A[ind[1]][ind[0]]=0;
	}
	int Res[SZ][SZ];
	toPow(A,Res,n-1,m);
	int res=0;
	rep(i,0,m)
		rep(j,0,m)
			res=(res+Res[i][j])%MOD;
	cout<<res<<endl;
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