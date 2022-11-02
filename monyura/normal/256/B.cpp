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

ll getCnt(int x,int y,int n,int a)
{
	ll sum = 2*a*ll(a-1) + 1;
	ll up = max(0,a - x);
	ll ucnt = up*up;
	ll dwn = max(0,a - (n-x+1));
	ll dcnt = dwn*dwn;
	ll rght = max(0,a - (n-y+1));
	ll rcnt = rght*rght;
	ll lft = max(0,a - y);
	ll lcnt = lft*lft;
	sum-=ucnt + rcnt + dcnt + lcnt;

	ll dr = n - y +1;
	ll cornUR = max(0LL,a - x - dr);
	sum+=cornUR*(cornUR+1)/2;

	ll cornDR = max(0LL,a - (n-x+1) - dr);
	sum+=cornDR*(cornDR+1)/2;

	ll dl = y;
	ll cornUL = max(0LL,a - x - dl);
	sum+=cornUL*(cornUL+1)/2;

	ll cornDL = max(0LL,a - (n-x+1) - dl);
	sum+=cornDL*(cornDL+1)/2;
	return sum;
}

void run()
{	
	int n,x,y,c;
	cin>>n>>x>>y>>c;
	ll tmp;
	tmp = getCnt(1,1,1,1e9);
	int res=-1;
	int l=0,r=c;
	while (l<=r)
	{
		int mid = (l+r)>>1;
		if (getCnt(x,y,n,mid+1)>=c)
		{
			res=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	cout<<res<<endl;
}


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("freecell.in","r",stdin);
	//freopen("freecell.out","w",stdout);
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