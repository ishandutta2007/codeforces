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
typedef pair<ll,int> pli;

const int INF=1e9;

const int SZ=100100;
ll Sum[SZ];

//void add(int pos,int n,int val)
//{
//	pos++;
//	n++;
//	for (int i=pos;i<=n;i+=i&-i)
//		Fen[i]+=val;
//}
//
//ll getSum(int pos)
//{
//	if (pos<0) return 0;
//	pos++;
//	ll res=0;
//	for (int i=pos;i>0;i-=i&-i)
//		res+=Fen[i];
//	return res;
//}

ll sumab(int a,int b)
{
	if (a>b)
		return 0;
	ll otn=0;
	if (a-1>=0)
		otn=Sum[a-1];
	return Sum[b]-otn;
}


void run()
{
	int n,k;
	cin>>n>>k;
	int A[SZ];
	rep(i,0,n)
		scanf("%d",A+i);
	sort(A,A+n);
	pii best=pii(-1e9,1e9);
	Sum[0]=A[0];
	rep(i,1,n)
		Sum[i]=Sum[i-1]+A[i];

	rep(i,0,n)
	{
		int l=0,r=i;
		int res=0;
		while (l<=r)
		{
			int c=(l+r)>>1;
			if (ll(c)*A[i] - sumab(i-c,i-1)<=k)
			{
				res=c;
				l=c+1;
			}
			else
				r=c-1;
		}
		pii curr(res + 1,A[i]);
		if (curr.first>best.first)
			best=curr;
	}
	printf("%d %d\n",best.first,best.second);

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