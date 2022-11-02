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

//int getAns(int *P,int n)
//{
//	int best=1e9;
//	rep(i,0,1<<n)
//	{
//		vector<int> A;
//		vector<int> B;
//		rep(j,0,n)
//			if ((i>>j)&1)
//			{
//				A.push_back(P[i]);
//			}
//			else
//				B.push_back(P[i]);
//		in
//	}
//}

void run()
{
	int n,h;
	cin>>n>>h;
	int res=1e9;
	pii P[200100];
	int A[200100];
	int R[200100];
	rep(i,0,n)
	{
		scanf("%d",A+i);
		P[i]=pii(A[i],i);
	}
	sort(P,P+n);
	rep(i,0,n)
		A[i]=P[i].first;
	int to=0;
	if (n==2)
	{
		res=0;
		to=0;
	}
	else
	{
		res = A[n-1]+A[n-2] - A[0] - A[1];
		to=0;
		int mx=max(A[n-1]+A[n-2],A[n-1]+A[0]+h);
		int mn=min(A[1]+A[0]+h,A[1]+A[2]);
		if (res>mx-mn)
		{
			to=1;
			res=mx-mn;
		}
		mx=A[n-1]+A[n-2]+h;
		mn=A[0]+A[1];
		if (res>mx-mn)
		{
			to=n-1;
			res=mx-mn;
		}
		rep(i,1,n-2)
		{
			mx=max(A[n-1]+A[n-2],A[i]+A[n-1]+h);
			mn=A[0]+A[1];
			if (res>mx-mn)
			{
				to=i+1;
				res=mx-mn;
			}
		}
	}
	cout<<res<<endl;
	rep(i,0,to)
		R[P[i].second]=1;
	rep(i,to,n)
		R[P[i].second]=2;
	rep(i,0,n)
		printf("%d ",R[i]);
	puts("");
}


int main()
{
	srand(time(0));
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("final.in","r",stdin);
	//freopen("final.out","w",stdout);
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