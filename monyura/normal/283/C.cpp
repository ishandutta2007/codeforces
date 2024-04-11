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

const double PI = acos(-1.0);

ll mnVal[501]={0};
int was[501]={0};
vector<int> inc[501];
vector<int> back[501];
int A[501];
ll S[501];
bool cicle = false;

void dfs(int k)
{
	if (was[k])
	{
		if (was[k]==1)
			cicle = true;
		return;
	}
	was[k]=1;
	rep(i,0,inc[k].size())
	{
		dfs(inc[k][i]);
		mnVal[k] = mnVal[inc[k][i]]+1;
	}
	was[k]=2;
}

void revDfs(int k,int dummy)
{
	if (was[k])
		return;
	was[k] = 2;
	S[k] = A[k];
	rep(i,0,back[k].size())
	{
		revDfs(back[k][i],dummy);
		S[k] += S[back[k][i]];
	}
}

const int mod = 1e9 + 7;
void run()
{
	int n,q,t;
	cin>>n>>q>>t;
	rep(i,0,n)
		scanf("%d",A+i);
	rep(i,0,q)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		inc[a].push_back(b);
		back[b].push_back(a);
	}
	cicle = false;
	rep(i,0,n)
		if (!was[i])
			dfs(i);
	ll need = 0;
	rep(i,0,n)
		need += mnVal[i]*ll(A[i]);
	if (cicle || need>t)
	{
		puts("0");
		return;
	}
	memset(was,0,sizeof(was));
	rep(i,0,n)
		if (!was[i])
			revDfs(i,0);
	t-=need;
	int D[100010]={1};
	rep(j,0,n)
		rep(i,1,t+1)
			if (i-S[j]>=0)
			{
				D[i] += D[i-S[j]];
				if (D[i]>mod)
					D[i]-=mod;
			}
	cout<<D[t]<<endl;
	
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
3
abcdefghABCDEFGH
3
abc
a
abAB
xyz
1
xyz
abacaba
6
a
aba
caba 
acaba
ba
bacb
*/