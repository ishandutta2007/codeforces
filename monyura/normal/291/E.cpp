//#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
//#endif

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

const double PI = acos(-1.0);

const int MAX_N = 300300;

int mod1 = 1e9+9;
int mod2 = 999999937;
ll c1 = 17531;
ll c2 = 19;

ll c1Pow;
ll c2Pow;

pll Hash[MAX_N];

pll calcHash(int l,int r)
{
	pll res = Hash[r];
	res.first = (res.first - c1Pow*Hash[l-1].first) % mod1;
	res.second = (res.second - c2Pow*Hash[l-1].second) % mod2;
	if (res.first<0) res.first+=mod1;
	if (res.second<0) res.second+=mod2;
	return res;
}


struct vert
{
	vector<int> inc;
	vector<char*> str;
	int d;
} g[100100];

pll goalHash;
int len;
int res;

void dfs(int k,int depth)
{
	g[k].d = depth;
	rep(i,0,g[k].inc.size())
	{
		depth = g[k].d;
		char *str = g[k].str[i];
		for (int j=0;str[j];++j,++depth)
		{
			Hash[depth].first = (Hash[depth-1].first*c1 + str[j])%mod1;
			Hash[depth].second = (Hash[depth-1].second*c2 + str[j])%mod2;
			if (depth>=len && calcHash(depth-len+1,depth)==goalHash)
				++res;
		}
		dfs(g[k].inc[i],depth);
	}
}

void run()
{
	char BUFF[2*MAX_N + 3]={0};
	int n;
	cin>>n;
	char *curr = BUFF;
	rep(i,0,n-1)
	{
		int p;
		scanf("%d %s",&p,curr);
		--p;
		g[p].inc.push_back(i+1);
		g[p].str.push_back(curr);
		curr+=strlen(curr)+1;
	}
	char str[MAX_N];
	scanf("%s",str);
	len = strlen(str);
	c1Pow  = c2Pow = 1;
	rep(i,0,len)
	{
		c1Pow = (c1Pow*c1)%mod1;
		c2Pow = (c2Pow*c2)%mod2;
	}
	goalHash=pll(0,0);
	rep(i,0,len)
	{
		goalHash.first = (goalHash.first*c1 + str[i])%mod1;
		goalHash.second = (goalHash.second*c2 + str[i])%mod2;
	}
	res = 0;
	Hash[0]=pll(0,0);
	dfs(0,1);
	printf("%d\n",res);
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
	printf( "=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}