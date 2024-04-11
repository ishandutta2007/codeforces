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

ll Sum[100100];
vector<int> S[200100];
vector<int> pos[100100];
bool isSmal[100100]={0};
vector<pii> bigOnes[100100];
ll bigAdd[100100];
ll bigS[100100];
void run()
{
	int n,m,q;
	int A[100100];
	cin>>n>>m>>q;
	rep(i,0,n)
	{
		scanf("%d",A+i);
		Sum[i] = A[i];
	}
	vector<int> large;
	rep(i,0,m)
	{
		int k;
		scanf("%d",&k);
		S[i].resize(k);
		rep(j,0,k)
		{
			scanf("%d",&S[i][j]);
			--S[i][j];
			bigS[i] += A[S[i][j]];
			pos[S[i][j]].push_back(i);
		}
		if (k<330)
			isSmal[i] = 1;
		else
			large.push_back(i);
	}
	vector<int> big;
	big.resize(m);
	rep(i,0,n)
	{
		big.clear();
		rep(j,0,pos[i].size())
		{
			if (!isSmal[pos[i][j]])
				big.push_back(pos[i][j]);
		}
		rep(j,0,pos[i].size())
		{
			rep(k,0,big.size())
				bigOnes[pos[i][j]].push_back(pii(big[k],1));
		}
	}
	rep(i,0,m)
	{
		sort(all(bigOnes[i]));
		int pos = 0;
		rep(j,1,bigOnes[i].size())
			if (bigOnes[i][pos].first == bigOnes[i][j].first)
				bigOnes[i][pos].second++;
			else
			{
				++pos;
				bigOnes[i][pos].first = bigOnes[i][j].first;
				bigOnes[i][pos].second = 1;
			}
		bigOnes[i].resize(pos+1);
	}
	rep(i,0,q)
	{
		char c;
		scanf(" %c",&c);
		if (c=='?')
		{
			int k;
			scanf("%d",&k);
			--k;
			ll res = 0;
			rep(j,0,bigOnes[k].size())
				res += bigAdd[bigOnes[k][j].first] * ll(bigOnes[k][j].second);
			if (isSmal[k])
			{
				rep(j,0,S[k].size())
					res += Sum[S[k][j]];
			}
			else
			{
				res += bigS[k];
			}
			printf("%I64d\n",res);
		}
		else
		{
			int k,x;
			scanf("%d%d",&k,&x);
			--k;
			if (isSmal[k])
			{
				rep(j,0,S[k].size())
					Sum[S[k][j]] += x;
				rep(j,0,bigOnes[k].size())
					bigS[bigOnes[k][j].first] += x*ll(bigOnes[k][j].second);
			}
			else
			{
				bigAdd[k] += x;
			}
		}
	}
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