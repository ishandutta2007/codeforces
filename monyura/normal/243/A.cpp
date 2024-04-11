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
	set<int> st;
	int Pos[33];
	rep(i,0,33)
		Pos[i]=-1;
	vector<int> res;
	vector<pii> vec;
	vec.reserve(300);
	rep(i,0,n)
	{
		int a;
		scanf("%d",&a);
		if (a==0)
			res.push_back(a);
		rep(j,0,22)
			if ((a>>j)&1)
				Pos[j]=i;
		vec.clear();
		rep(j,0,22)
			if (Pos[j]!=-1)
				vec.push_back(pii(i-Pos[j],j));
		sort(all(vec));
		int curr=0;
		for (int j=0;j<vec.size();)
		{
			int st=j;
			while (j<vec.size() && vec[j].first==vec[st].first)
				++j;
			rep(k,st,j)
				curr|=(1<<vec[k].second);
			res.push_back(curr);
		}
	}
	sort(all(res));
	int ans=unique(all(res)) - res.begin();
	cout<<ans<<endl;
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