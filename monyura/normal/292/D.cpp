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

const double PI = acos(-1.0);
int A[10];
int cnt;
vector<string> res;

int pred[501];
int get(int a)
{
	if (pred[a]!=a)
		pred[a] = get(pred[a]);
	return pred[a];
}

void uni(int a,int b)
{
	pred[get(a)]=get(b);
}
pii E[10001];

int apply(int i)
{
	if (get(E[i].first)!=get(E[i].second))
	{
		uni(E[i].first,E[i].second);
		return 1;
	}
	return 0;
}

struct quer
{
	int l,r;
	int ind;
	bool operator<(const quer &a) const
	{
		return l<a.l;
	}
};

void run()
{
	int n,m;
	cin>>n>>m;
	rep(i,0,m)
	{
		scanf("%d%d",&E[i].first,&E[i].second);
		--E[i].first;
		--E[i].second;
	}
	vector<quer> V[300];
	int RT = sqrt((double)m)+10;
	int q;
	cin>>q;
	rep(i,0,q)
	{
		quer a;
		scanf("%d%d",&a.l,&a.r);
		--a.l;--a.r;
		a.ind  = i;
		V[a.r/RT].push_back(a);
	}
	int Ans[30001];
	rep(t,0,150)
		if (!V[t].empty())
		{
			vector<quer> &v= V[t];
			int mxr = -1;
			rep(i,0,v.size())
				mxr=max(mxr,v[i].r);
			sort(all(v));
			int curr[501];
			rep(i,0,n)
				pred[i] = i;
			int cnt = n;
			rep(i,0,v[0].l)
				cnt-=apply(i);
			rep(i,mxr+1,m)
				cnt-=apply(i);
			int l = v[0].l;
			rep(i,0,v.size())
			{
				while(l<v[i].l)
				{
					cnt-=apply(l);
					l++;
				}
				memcpy(curr,pred,sizeof(curr));
				int ans = cnt;
				rep(j,v[i].r+1,mxr+1)
					ans-=apply(j);
				Ans[v[i].ind] = ans;
				memcpy(pred,curr,sizeof(curr));
			}
		}
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
	//freopen("path.in","r",stdin);
	//freopen("path.out","w",stdout);
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