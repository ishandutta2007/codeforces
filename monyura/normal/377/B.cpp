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

const double PI = acos(-1.0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<double,int> pdi;
typedef pair<int,double> pid;

struct stud
{
	int b;
	int cost;
	int ind;
	bool operator<(const stud &other) const
	{
		return b < other.b;
	}
};

int Res[100100];
bool can(pii *A, stud *S ,int n, int m, int s, int days)
{
	ll sum = 0;
	int pos = n-1;
	const int INF = 2e9;
	int minCost = INF;
	int minId = -1;
	set<pii> st;
	set<pii>::iterator iter;
	for (int j = m-1; j>=0;)
	{
		while (pos>=0 && S[pos].b >= A[j].first)
		{
			st.insert(pii(S[pos].cost,S[pos].ind));
			--pos;
		}
		iter = st.begin();
		if (iter == st.end())
			return false;
		sum += iter->first;
		rep(i,0,min(days,j+1))
		{
			Res[A[j].second] = iter->second;
			--j;
		}
		st.erase(iter);
	}
	return sum <= s;
}



void run()
{
	stud S[100100];
	pii A[100100];
	int n,m,s;
	cin>>n>>m>>s;
	rep(i,0,m)
	{
		scanf("%d",&A[i].first);
		A[i].second = i;
	}
	rep(i,0,n)
		scanf("%d",&S[i].b);
	rep(i,0,n)
	{
		scanf("%d",&S[i].cost);
		S[i].ind = i;
	}
	sort(A,A+m);
	sort(S,S+n);
	int res = -1;
	int l = 1, r = m;
	while (l<=r)
	{
		int c = (l+r)>>1;
		if (can(A,S,n,m,s,c))
		{
			res = c;
			r = c-1;
		}
		else
		{
			l = c+1;
		}
	}
	if (res != -1)
	{
		puts("YES");
		can(A,S,n,m,s,res);
		rep(i,0,m)
			printf("%d ",Res[i]+1);
		puts("");
	}
	else
	{
		puts("NO");
	}
}	


//#define prob "xoring"


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
		//testFft();
#ifdef _MONYURA_
	printf( "\n=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}