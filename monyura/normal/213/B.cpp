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

const int mod=1000000007;

int D[101][10]={0};
ll C[102][102]={0};
int A[10];

int getCnt(int n,int last)
{
	if (D[n][last]!=-1) return D[n][last];
	int res=0;
	if (last!=0)
	{
		rep(i,A[last],n+1)
			res=(res+C[n][i]*getCnt(n-i,last+1))%mod;
	}
	else
	{
		rep(i,A[last],n)
			res=(res+C[n-1][i]*getCnt(n-i,last+1))%mod;
	}
	return D[n][last]=res;
	
}

void run()
{
	memset(D,-1,sizeof(D));
	rep(i,0,102)
		C[i][0]=1;
	rep(i,1,102)
		rep(j,1,102)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	int n;
	cin>>n;
	rep(i,0,10)
		scanf("%d",A+i);
	rep(i,0,101)
		D[i][9]=0;
	rep(i,A[9],101)
		D[i][9]=1;
	int res=0;
	rep(i,0,n+1)
		res=(res+getCnt(i,0))%mod;
	printf("%d\n",res);

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