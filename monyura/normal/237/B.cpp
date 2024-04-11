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


void run()
{
	int n;
	cin>>n;
	int C[51];
	rep(i,0,n)
		scanf("%d",C+i);
	int A[100][100];
	pii P[3000];
	rep(i,0,n)
		rep(j,0,C[i])
		{
			scanf("%d",&A[i][j]);
			P[A[i][j]]=pii(i,j);
		}
	vector<pii> F;
	vector<pii> T;
	int cnt=1;
	rep(i,0,n)
		rep(j,0,C[i])
		{
			if (A[i][j]!=cnt)
			{
				pii p=P[cnt];
				P[A[i][j]]=p;
				swap(A[i][j],A[p.first][p.second]);
				F.push_back(pii(i,j));
				T.push_back(p);
			}
			++cnt;
		}
	printf("%d\n",F.size());
	rep(i,0,F.size())
		printf("%d %d %d %d\n",F[i].first+1,F[i].second+1,T[i].first+1,T[i].second+1);
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