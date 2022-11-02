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
	char A[5010],B[5010];
	scanf("%s %s",A,B);
	int D[5010][5010]={0};
	int M=1000000007;
	int n=strlen(A);
	int m=strlen(B);
	ll res=0;
	rep(i,0,m)
	{
		rep(j,0,n)
		{
			if (i!=0)
			{
				D[i][j]=(D[i-1][j]+D[i][j])%M;
				if (j!=0 && A[j]==B[i])
					D[i][j]=(D[i-1][j-1]+D[i][j])%M;
			}
			if (A[j]==B[i])
				D[i][j]=(D[i][j]+1)%M;
		}
	}
	rep(j,0,n)
		res=(res+D[m-1][j])%M;
	cout<<res<<endl;
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