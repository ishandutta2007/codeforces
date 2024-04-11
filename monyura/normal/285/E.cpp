//#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
//#endif

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

const int mod  = 1e9+7;
int getCnt(int n,int K)
{
	if (K>n)
		return 0;
	if (n==1)
		return 1-K;
	int D[1001][1001][2][2]={0};
	D[0][0][1][0] = 1;
	rep(i,1,n+1)
		rep(k,0,i+1)
			rep(a,0,2)
			{
				ll curr = D[i-1][k][1][a] + D[i-1][k][0][a];
				if (k!=0)
					curr+= D[i-1][k-1][0][a];
				D[i][k][a][0] = curr % mod;
				if (k!=0)
				{
					curr = D[i-1][k-1][1][a] + D[i-1][k-1][0][a];
					D[i][k][a][1] = curr % mod;
				}
			}
	int C[1001][1001];
	ll F[1001]={1};
	rep(i,1,1001)
		F[i] = (F[i-1]*i)%mod;
	rep(i,0,n+1)
		C[i][0]=1;
	rep(i,1,n+1)
		rep(j,1,n+1)
			C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
	ll res[1001];
	for (int i=n;i>=K;i--)
	{
		res[i]=0;
		rep(a,0,2)
			res[i] = (res[i] + D[n][i][a][0])%mod;
		res[i] = (res[i]*F[n-i])%mod;
		rep(j,i+1,n+1)
			res[i] = (res[i] - C[j][i]*res[j]) % mod;
		if (res[i]<0)
			res[i]+=mod;
	}
	return res[K];
}

void run()
{
	int n,k;
	cin>>n>>k;
	int res = getCnt(n,k);
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
3
abcdefghABCDEFGH
3
abc
a
abAB
xyz
1
xyz
abacaba
6
a
aba
caba 
acaba
ba
bacb
*/