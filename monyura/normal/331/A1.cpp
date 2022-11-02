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


void run()
{
	map<int,int> mp;
	int n;
	cin>>n;
	ll s = 0;
	ll S[300300]={0};
	int A[300100]={0};
	rep(i,0,n)
		scanf("%d",A+i);
	ll best = -1e18;
	pii ind;
	rep(i,0,n)
	{
		if (mp.find(A[i])!=mp.end())
		{
			ll val = S[mp[A[i]]];
			int add = 0;
			if (A[i]<=0) 
				add = 2*A[i];
			else
				add = A[i];
			if (s-val + add>best)
			{
				best = s - val + add;
				ind = pii(mp[A[i]],i);
			}
			if (s<val)
				mp[A[i]] = i;
		}
		else
			mp[A[i]] = i;
		S[i] = s;
		if (A[i]<0) continue;
		s+=A[i];
	}
	vector<int> ans;
	rep(i,0,ind.first)
		ans.push_back(i);
	rep(i,ind.first+1,ind.second)
		if (A[i]<0)
			ans.push_back(i);
	rep(i,ind.second+1,n)
		ans.push_back(i);
	cout<<best<<' ';
	printf("%d\n",ans.size());
	rep(i,0,ans.size())
		printf("%d ",ans[i]+1);
	puts("");
}

#define prob "victory"

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
    //freopen(prob".in","r",stdin);
    //freopen(prob".out","w",stdout);
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

    return 0;
}