#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
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

int ind(int a,int b)
{
	if (a==b)
		return 2;
	return a<b;
}
void run()
{
	int n;
	cin>>n;
	int A[100100];
	rep(i,0,n)
		scanf("%d",A+i);
	int G[3]={0};
	rep(i,1,n)
		G[ind(A[i-1],A[i])]++;
	rep(i,1,n)
		if (A[i]!=A[i-1])
		{
			int Was[3];
			memcpy(Was,G,sizeof(int)*3);
			if (i-2>=0)
				G[ind(A[i-2],A[i-1])]--;
			if (i+1<n)
				G[ind(A[i],A[i+1])]--;
			G[ind(A[i-1],A[i])]--;
			swap(A[i],A[i-1]);
			G[ind(A[i-1],A[i])]++;
			if (i-2>=0)
				G[ind(A[i-2],A[i-1])]++;
			if (i+1<n)
				G[ind(A[i],A[i+1])]++;
			if (G[0]!=0 && G[1]!=0)
			{
				printf("%d %d\n",i,i+1);
				return;
			}
			swap(A[i],A[i-1]);
			memcpy(G,Was,sizeof(int)*3);
		}
	puts("-1");
}


int main()
{
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
10 10 10 10 1 1
2 2 1 1 1 2
5 5 3 3  5 5
6 6 1 1 1 1
*/