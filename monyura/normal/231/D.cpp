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

void run()
{
	
	int x,y,z;
	int x1,y1,z1;
	cin>>x>>y>>z;
	cin>>x1>>y1>>z1;
	int A[6];
	rep(i,0,6)
		scanf("%d",A+i);
	int res=0;
	if (y<0) res+=A[0];
	if (y>y1) res+=A[1];
	if (z<0) res+=A[2];
	if (z>z1) res+=A[3];
	if (x<0) res+=A[4];
	if (x>x1) res+=A[5];
	cout<<res<<endl;
	

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