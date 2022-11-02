#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
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
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int D[1000100]={0};
int X[100100];
int maxDel[1000100];
void run()
{
	int n;
	cin>>n;
	rep(i,0,n)
		scanf("%d",X+i);
	sort(X,X+n);
	n = unique(X,X+n) - X;
	int a,b;
	cin>>b>>a;
	for (int i = 0; i < n; i++)
		for (int j = (a+X[i]-1)/X[i]; j*ll(X[i])<=b; j++)
		{
			int &curr = maxDel[j*X[i] - a];
			curr = max(curr, X[i]);
		}
	int INF = 1e9;
	priority_queue<pii> q;
	for (int i = 0; i < b-a+1; i++)
	{
		if (i!=0)
			D[i] = D[i-1]+1;
		while (!q.empty() && q.top().second <= i)
			q.pop();
		if (!q.empty() && -q.top().first + 1 < D[i])
			D[i] = -q.top().first + 1;
		q.push(pii(-D[i],i + maxDel[i]));
	}
	cout<<D[b-a]<<endl;
}

//#define prob "tria"

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
	#ifdef prob
		freopen(prob".in","r",stdin);
		freopen(prob".out","w",stdout);
	#endif
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

    return 0;
}