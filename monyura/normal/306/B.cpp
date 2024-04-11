#pragma comment(linker,"/STACK:65000000")
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
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <assert.h>


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
typedef vector<int> vi;

const double PI = acos(-1.0);

struct elem
{
	int l,r;
	int ind;
	bool operator<(const elem &b) const
	{
		if (l!=b.l)
			return l<b.l;
		return r>b.r;
	}
};

void run()
{
	int n,m;
	cin>>n>>m;
	elem A[200200];
	rep(i,0,m)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		A[i].l=a;
		A[i].r=a+b-1;
		A[i].ind = i;
	}
	sort(A,A+m);
	bool used[200200]={0};
	int res = m;
	int last = -1;
	int i=0;
	while (i<m)
	{
		int asd=i;
		int mx = last,ind = -1;
		while (i<m && A[i].l<=last+1)
		{
			if (A[i].r > mx)
			{
				mx = A[i].r;
				ind = i;
			}
			++i;
		}
		if (i<m && mx==last)
		{
			ind = i;
			mx = A[i].r;
			++i;
		}
		if (ind==-1) break;
		last = mx;
		used[A[ind].ind] = true;
		--res;
	}
	cout<<res<<endl;
	rep(i,0,m)
		if (!used[i])
			printf("%d ",i+1);
	puts("");
}


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
24 54 96 108
*/