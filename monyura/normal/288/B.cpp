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



const int mod = 1e9+7;

int K;
int A[10];
int was[10];
bool one[10];
bool ok;
//void dfs(int i)
//{
//	was[i]=1;
//	if (i!=0)
//	{
//		if (was[A[i]]==1) ok=false;
//		if (was[A[i]]==0) dfs(A[i]);
//	}
//	was[i]=2;
//}

//void dfs(int i)
//{
//	if (i==0)
//	{
//		was[i]=2;
//		one[i]=1;
//		return;
//	}
//	was[i]=1;
//	if (was[A[i]]==1) 
//		ok=false;
//	if (was[A[i]]==0)
//		dfs(A[i]);
//	if (one[A[i]])
//		one[i]=1;
//	was[i]=2;
//}

bool dfs(int k)
{
	if (k==0) return true;
	was[k]=1;
	if (was[A[k]]==1) return false;
	return dfs(A[k]);
}

int res = 0;
void rec(int pos)
{
	if (pos==K)
	{
		ok = true;
		rep(i,0,K)
		{
			memset(was,0,sizeof(was));
			if (!dfs(i))
			{
				ok= false;
				break;
			}
		}
		/*memset(one,0,sizeof(one));
		ok = true;
		rep(i,0,K)
		{
			if (!was[i])
				dfs(i);
			if (!one[i])
				ok=false;
		}*/
		if (ok) ++res;
		return;
	}
	for (int i=0;i<K;++i)
	{
		A[pos] = i;
		rec(pos+1);
	}
}

ll toPow(ll a,int b)
{
	a%=mod;
	ll res = 1;
	while (b)
	{
		if (b&1)
			res =  (res*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return res;
}


void run()
{
	/*rep(k,1,9)
	{
		res=0;
		K=k;
		rec(0);
		cout<<res<<", ";
		cerr<<k<<endl;
	}
	cout<<endl;
	return;*/
	int A[9]={0,1, 2, 9, 64, 625, 7776, 117649, 2097152};
	int n,k;
	cin>>n>>k;
	ll res = A[k];
	ll pw = toPow(n-k,n-k);
	res = (res*pw)%mod;
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
	printf( "=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}