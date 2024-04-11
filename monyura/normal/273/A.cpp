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
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


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

const double PI=acos(-1.0);

ll Fen[100100]={0};

void addFen(int pos,ll val,int n)
{
	for (int i=pos;i<=n;i+=i&-i)
		Fen[i]=max(Fen[i],val);
}

ll getFen(int pos)
{
	ll res=0;
	for (int i=pos;i>0;i-=i&-i)
		res=max(res,Fen[i]);
	return res;
}


void run()
{
	int n;
	cin>>n;
	rep(i,1,n+1)
	{
		int a;
		scanf("%d",&a);
		addFen(i,a,n);
	}
	int m;
	cin>>m;
	rep(i,0,m)
	{
		int w,h;
		scanf("%d%d",&w,&h);
		ll ans = getFen(w);
		cout<<ans<<endl;
		addFen(1,ans+h,n);
	}
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
10 10 92
11 10 92
*/