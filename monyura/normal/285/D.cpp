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

//ll calc(int n)
//{
//	int A[100];
//	int B[100];
//	int res=0;
//	rep(i,0,n)
//		A[i]=B[i]=i;
//	do
//	{
//		sort(A,A+n);
//		do
//		{
//			bool was[10]={0};
//			bool ok = true;
//			rep(i,0,n)
//			{
//				int x = (A[i]+B[i])%n;
//				if (was[x])
//					ok=false;
//				was[x]=1;
//			}
//			res+=ok;
//		}
//		while(next_permutation(A,A+n));
//	}
//	while (next_permutation(B,B+n));
//	return res;
//}

const int mod = 1e9+7;

int was[20]={0};
bool used[20]={0};
int n;
int res=0;
void rec(int pos)
{
	if (pos==n)
		++res;
	else
	{
		for (int i=0;i<n;i++)
			if (!used[i])
			{
				int nxt = pos + i;
				if (nxt>=n) nxt-=n;
				if (!was[nxt])
				{
					was[nxt]=1;
					used[i] = 1;
					rec(pos+1);
					used[i] = 0;
					was[nxt]=0;
				}
			}
	}
}


void run()
{
	/*rep(i,1,17)
	{
		if (!(i&1))
			printf("0");
		else
		{
			n = i;
			res = 0;
			rec(0);
			printf("%d",res);
		}
		printf(", ");
		cerr<<i<<endl;
	}*/
	ll A[17]={0,1, 0, 3, 0, 15, 0, 133, 0, 2025, 0, 37851, 0, 1030367, 0, 36362925, 0};
	ll f = 1;
	int n;
	cin>>n;
	rep(i,2,n+1)
		f=(f*i)%mod;
	ll res = (f * A[n])%mod;
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