//#pragma comment(linker,"/STACK:128000000")
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
	int n,m;
	cin>>n>>m;
	if (n==0 && m!=0)
	{
		puts("Impossible");
		return;
	}
	int r1=n+m-min(n,m);
	int r2=n+m-(m!=0);
	cout<<r1<<' '<<r2<<endl;
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