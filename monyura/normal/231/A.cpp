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

void generateTest(char *fname)
{
	FILE *f=fopen(fname,"w");
	int n = 5000;
	fprintf(f,"%d\n",n);
	rep(i,0,n)
		fprintf(f,"%d ",100000-i);
	fprintf(f,"\n");
}



void run()
{
	int n;
	cin>>n;
	int res=0;
	rep(i,0,n)
	{
		int a;
		int s=0;
		rep(j,0,3)
		{
			scanf("%d",&a);
			s+=a;
		}
		res += s>=2;
	}
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