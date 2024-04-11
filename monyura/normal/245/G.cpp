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
	int m;
	cin>>m;
	map<string,int> mp;
	char A[100],B[100];
	vector<int> inc[10001];
	rep(i,0,m)
	{
		scanf("%s%s",A,B);
		if (mp.find(A)==mp.end())
		{
			int id=mp.size();
			mp[A]=id;
		}
		if (mp.find(B)==mp.end())
		{
			int id=mp.size();
			mp[B]=id;
		}
		inc[mp[A]].push_back(mp[B]);
		inc[mp[B]].push_back(mp[A]);
	}
	int Res[10001]={0};
	bool Ok[10001]={0};
	int n=mp.size();
	rep(i,0,n)
	{
		rep(k,0,inc[i].size())
			Ok[inc[i][k]]=1;
		int mx=-1;
		int cnt=0;
		rep(j,0,n)
			if (!Ok[j] && j!=i)
			{
				int curr=0;
				rep(k,0,inc[j].size())
					curr+=Ok[inc[j][k]];
				if (curr>mx)
				{
					cnt=0;
					mx=curr;
				}
				if (curr==mx)
					++cnt;
			}
		Res[i]=cnt;
		rep(k,0,inc[i].size())
			Ok[inc[i][k]]=0;
	}
	int i=0;
	cout<<n<<endl;
	string S[10001];
	for (map<string,int>::iterator iter=mp.begin();iter!=mp.end();iter++)
		S[iter->second]=iter->first;
	rep(i,0,n)
	{
		printf("%s %d\n",S[i].c_str(),Res[i]);
	}
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