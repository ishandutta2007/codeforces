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

const int SZ=2e5+100;
int F[SZ]={0};
void add(int pos,int val)
{
	++pos;
	for (int i=pos;i>0;i-=i&-i)
		F[i]+=val;
}

int get(int pos)
{
	++pos;
	int res = 0;
	for (int i=pos;i<SZ;i+=i&-i)
		res+=F[i];
	return res;
}

void proc(int *A,int n,vector<pii> *Q,int *Ans)
{
	int pos[SZ];
	memset(pos,-1,sizeof(pos));
	rep(i,0,n)
	{
		int a=A[i];
		for (int j=1;j*j<=a;++j)
			if (a%j==0)
			{
				if (pos[j]!=-1)
					add(pos[j],1);
				if (j*j!=a && pos[a/j]!=-1)
					add(pos[a/j],1);
			}
		rep(j,0,Q[i].size())
			Ans[Q[i][j].second]+=get(Q[i][j].first);
		pos[a]=i;
	}
}

void run()
{
	int n,q;
	cin>>n>>q;
	int A[SZ];
	rep(i,0,n)
		scanf("%d",A+i);
	pii Z[SZ];
	rep(i,0,q)
	{
		scanf("%d%d",&Z[i].first,&Z[i].second);
		--Z[i].first;--Z[i].second;
	}
	vector<pii> Q[SZ];
	int Ans[SZ]={0};
	rep(i,0,q)
		Q[Z[i].second].push_back(pii(Z[i].first,i));
	proc(A,n,Q,Ans);

	memset(F,0,sizeof(F));
	rep(i,0,n)
		Q[i].clear();
	rep(i,0,q)
		Q[n-1-Z[i].first].push_back(pii(n-1-Z[i].second,i));
	reverse(A,A+n);
	proc(A,n,Q,Ans);

	rep(i,0,q)
		Ans[i]+=Z[i].second-Z[i].first+1;
	rep(i,0,q)
		printf("%d\n",Ans[i]);
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