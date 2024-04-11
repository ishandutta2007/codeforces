#pragma comment(linker,"/STACK:128000000")
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

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

void run()
{
	int n,m,r;
	cin>>n>>m>>r;
	int D[61][61][61];
	int B[61][61];
	int INF=1e9;
	rep(i,0,n)
		rep(j,0,n)
		B[i][j]=INF;
	rep(i,0,m)
		rep(j,0,n)
			rep(k,0,n)
				scanf("%d",&D[i][j][k]);
	rep(c,0,m)
	{
		rep(k,0,n)
		rep(i,0,n)
		rep(j,0,n)
			movmin(D[c][i][j],D[c][i][k]+D[c][k][j]);
		rep(i,0,n)
			rep(j,0,n)
			movmin(B[i][j],D[c][i][j]);
	}
	int Ans[61][61][61];
	rep(i,0,n)
		rep(j,0,n)
			Ans[i][j][0]=B[i][j];
	rep(t,1,61)
	{
		rep(i,0,n)
		rep(j,0,n)
		{
			Ans[i][j][t]=Ans[i][j][t-1];
			rep(k,0,n)
				movmin(Ans[i][j][t],Ans[i][k][t-1]+B[k][j]);
		}
	}
	rep(i,0,r)
	{
		int s,t,k;
		scanf("%d%d%d",&s,&t,&k);
		if (k>60) k=60;
		--s;--t;
		printf("%d\n",Ans[s][t][k]);
	}
			
}

int main()
{

#ifdef _MON_JUDGE_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif
	time_t beg=clock();
	run();
#ifdef _MON_JUDGE_
	puts("=================");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/