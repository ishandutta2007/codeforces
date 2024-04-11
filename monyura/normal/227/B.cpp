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


const int SZ=1e6+1;
bool pr[SZ];


void run()
{
	int n;
	int A[100100];
	cin>>n;
	rep(i,0,n)
		scanf("%d",A+i);
	int R[100100];
	rep(i,0,n)
		R[A[i]]=i+1;
	int m;
	cin>>m;
	ll v=0;
	ll p=0;
	rep(i,0,m)
	{
		int a;
		scanf("%d",&a);
		v+=R[a];
		p+=n-R[a]+1;
	}
	cout<<v<<' '<<p<<endl;
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