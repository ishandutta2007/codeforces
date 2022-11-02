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

int tmp[101];
void forw(int q[101],int p[101],int n)
{
	rep(i,0,n)
		tmp[i]=p[i];
	rep(i,0,n)
		p[i]=tmp[q[i]];
}

void rev(int q[101],int p[101],int n)
{
	rep(i,0,n)
		tmp[i]=p[i];
	rep(i,0,n)
		p[q[i]] = tmp[i];
}

bool same(int p[101],int q[101],int n)
{
	return memcmp(p,q,sizeof(int)*n)==0;
}


void run()
{
	int n,k;
	cin>>n>>k;
	int p[101];
	rep(i,0,n)
		p[i]=i;
	int q[101];
	int M[101];
	rep(i,0,n)
	{
		scanf("%d",q+i);
		--q[i];
	}
	rep(i,0,n)
	{
		scanf("%d",M+i);
		--M[i];
	}
	if (same(p,M,n) && k!=0)
	{
		puts("NO");
		return;
	}
	int Curr[101];
	rep(cnt,0,k/2+1)
	{
		int lft=k-2*cnt;
		rep(i,0,n)
			p[i]=i;
		bool ok=1;
		rep(i,0,cnt)
		{
			forw(q,p,n);	
			if (same(p,M,n))
				ok=0;
			rev(q,p,n);
			if (same(p,M,n) && lft!=0)
				ok=0;
		}
		if (!ok)
		{
			rep(i,0,n)
				p[i]=i;
			ok=1;
			rep(i,0,cnt)
			{
				rev(q,p,n);	
				if (same(p,M,n))
					ok=0;
				forw(q,p,n);
				if (same(p,M,n) && lft!=0)
					ok=0;
			}
		}
		bool tmpok=ok;
		rep(i,0,n)
			Curr[i]=p[i];
		rep(i,0,lft)
		{
			forw(q,p,n);
			if (i!=lft-1 && same(p,M,n))
				ok=0;
		}
		if (!same(p,M,n))
			ok=0;
		if (ok)
		{
			puts("YES");
			return;
		}
		//
		rep(i,0,n)
			p[i]=Curr[i];
		ok=tmpok;
		rep(i,0,lft)
		{
			rev(q,p,n);
			if (i!=lft-1 && same(p,M,n))
				ok=0;
		}
		if (!same(p,M,n))
			ok=0;
		if (ok)
		{
			puts("YES");
			return;
		}
	}
	puts("NO");
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
10 10 10 10 1 1
2 2 1 1 1 2
5 5 3 3  5 5
6 6 1 1 1 1
*/