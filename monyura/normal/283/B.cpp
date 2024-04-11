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

int was[200200]={0};
ll D[200200]={0};
int Ar[200200];
int Cl[200200]={0};
int clCnt = 1;
int n;

ll dfs(int x)
{
	if (x<=0 || x>n)
		return 0;
	if (x==1 || was[x]==1)
		return -1;
	if (was[x]==2)
		return D[x];
	int prX = x;
	was[prX]=1;
	Cl[x]=clCnt;
	int add = Ar[x-1];
	ll y=0;
	x+=add;
	y+=add;
	if (x<=0 || x>n)
	{
		was[prX]=2;
		return D[prX]=y;
	}
	y+=Ar[x-1];
	x-=Ar[x-1];
	ll nxt = dfs(x);
	if (nxt==-1)
		y=-1;
	else
		y+=nxt;
	was[prX]=2;
	return D[prX]=y;
}

ll go(int *A,int n)
{
	int x=1;
	ll y=0;
	bool was[200200]={0};
	while (1)
	{
		if (x<=0 || x>n || was[x]) break;
		was[x]=1;
		int add = A[x-1];
		x+=add;
		y+=add;
		if (x<=0 || x>n) break;
		y+=A[x-1];
		x-=A[x-1];
		
	}
	if (x>0 && x<n)
		return -1;
	return y;
}

ll getRes()
{
	int x=1;
	ll y =0;
	int add = Ar[0];
	x+=add;
	y+=add;
	if (x<0 || x>n)
		return y;
	y+=Ar[x-1];
	x-=Ar[x-1];
	if (x<0 || x>n)
		return y;
	ll nxt = dfs(x);
	if (nxt==-1)
		return -1;
	return nxt + y;
}

void run()
{
	cin>>n;
	srand(time(0));
	rep(i,0,n-1)
	{
		scanf("%d",Ar+i+1);
	}
	Ar[0]=1;
	rep(i,0,n)
		if (was[i+1]==0)
		{
			dfs(i+1);
			clCnt++;
		}
	//ll Res[100]={0};
	rep(i,0,n-1)
	{
		Ar[0]=i+1;
		ll res = getRes();
		//Res[i]=res;
		printf("%I64d\n",res);
		//cout<<res<<endl;
	}
	/*rep(i,0,n-1)
	{
		Ar[0]=i+1;
		ll y =go(Ar,n);
		if (Res[i]!=y)
		{
			cerr<<"fail"<<endl;
			rep(i,0,n)
				printf("%d ",Ar[i]);
			return;
		}
	}*/
	
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