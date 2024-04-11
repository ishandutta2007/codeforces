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


void fill(int n,int m,int A[1002][1002],ll Res[1002][1002])
{
	ll Levee[1003]={0};
	rep(j,0,m)
	{
		Levee[j+1]=Levee[j];
		rep(i,0,n)
			Levee[j+1]+=A[i][j];
	}
	ll Vishe[1003]={0};
	rep(i,0,n)
	{
		Vishe[i+1]=Vishe[i];
		rep(j,0,m)
			Vishe[i+1]+=A[i][j];
	}
	ll sum=0;
	ll res=5e18;
	ll topSum=0,topDist=0,topSq=0;
	rep(i,0,n+1)
	{
		ll leftSum=0,leftDist=0,leftSq=0;
		rep(j,0,m+1)
		{
			Res[i][j]+=leftSq+topSq;
			leftSq+=8*leftDist+16*leftSum;
			leftDist+=4*leftSum;
			ll levee=Levee[j+1]-Levee[j];
			leftSum+=levee;
			leftDist+=2*levee;
			leftSq+=4*levee;
		}
		topSq+=8*topDist+16*topSum;
		topDist+=4*topSum;
		ll vishe=Vishe[i+1]-Vishe[i];
		topSum+=vishe;
		topDist+=2*vishe;
		topSq+=4*vishe;
	}
}

template<class T>
void perevernut(int n,int m,T A[1002][1002])
{
	rep(i,0,n/2)
		rep(j,0,m)
			swap(A[i][j],A[n-i-1][j]);
	rep(i,0,n)
		rep(j,0,m/2)
			swap(A[i][j],A[i][m-j-1]);
}

void run()
{
	int n,m;
	cin>>n>>m;
	int A[1002][1002];
	rep(i,0,n)
		rep(j,0,m)
			scanf("%d",&A[i][j]);
	ll Res[1002][1002]={0};
	fill(n,m,A,Res);
	perevernut(n,m,A);
	perevernut(n+1,m+1,Res);
	fill(n,m,A,Res);
	perevernut(n+1,m+1,Res);
	int x=0,y=0;
	ll ans=Res[0][0];
	rep(i,0,n+1)
		rep(j,0,m+1)
		if (Res[i][j]<ans)
		{
			ans=Res[i][j];
			x=i;
			y=j;
		}
	printf("%I64d\n%d %d\n",ans,x,y);
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