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

vector<int> inc[200200];

void run()
{
	/*char A[1000];
	scanf("%s",A);
	int deep=0;
	int res=0;
	int n=strlen(A);
	rep(a,0,n)
		rep(b,a,n)
		{
			deep=0;
			rep(i,a,b+1)
			{
				deep+=A[i]=='+' ? 1 : -1;
				res=max(res,abs(deep));
			}
		}
	cout<<res<<endl;
	*/
	int B[101][101];
	int n;
	cin>>n;
	rep(i,0,n)
	{
		rep(j,0,n)
			scanf("%d",&B[i][j]);
		B[i][i]=0;
	}
	int A[101]={0};
	rep(i,0,n)
		rep(j,0,n)
			A[i]|=B[i][j];
	/*rep(i,0,n)
		rep(j,i+1,n)
			if (A[i]&A[j]!=B[i][j])
				fprintf(stderr,"Error!");*/
	rep(i,0,n)
		printf("%d ",A[i]);
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
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
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