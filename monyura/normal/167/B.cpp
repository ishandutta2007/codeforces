#pragma comment(linker,"/STACK:200000000")
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
	int n,l,k;
	cin>>n>>l>>k;
	int P[1000];
	int A[1000];
	rep(i,0,n)
		scanf("%d",P+i);
	rep(i,0,n)
		scanf("%d",A+i);
	double D[202][202][402]={0};
	D[0][0][200+k]=1;
	rep(i,0,n+1)
		rep(j,0,n+1)
			rep(u,0,401)
				if (D[i][j][u]!=0)
				{
					int canuse=u;
					canuse+=A[i];
					if (canuse>400) canuse=400;
					if (canuse>=0)
						D[i+1][j+1][canuse]+=D[i][j][u]*P[i]/100.0;
					D[i+1][j][u]+=D[i][j][u]*(100-P[i])/100.0;
				}
	double res=0;
	rep(j,l,n+1)
		rep(sp,200,401)
			res+=D[n][j][sp];
	printf("%.9lf\n",res);
}

int main()
{

#ifdef _MON_JUDGE_
	freopen("test.txt","r",stdin);
	freopen("res.txt","w",stdout);
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