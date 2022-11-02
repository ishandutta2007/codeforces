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

void go(int n)
{
	int p[100100];
	//int n;
	//cin>>n;
	rep(i,0,n)
		p[i] = i;
	rep(st,2,n+1)
	{
		for (int i=0;i<n;i+=st)
		{
			int to = min(n,i+st);
			rotate(p+i,p+i+1,p+to);
		}
	}
	rep(i,0,n)
		printf("%d ",p[i]);
	puts("");
}

void run()
{
	int n;
	int p[1000100];
	cin>>n;
	rep(i,0,n)
		scanf("%d",p+i);
	int t;
	cin>>t;
	int q[1000100]={0};
	int ans[1000100];
	bool ok = !(n&1) && (t<=n/2);
	rep(i,0,t)
	{
		int a;
		scanf("%d",&a);
		--a;
		q[a] = 1;
	}
	rep(i,0,n)
		ans[i]=p[i];
	sort(p,p+n);
	int cnt=0;
	for (int i=0;i<n;)
	{
		int st = i;
		while (i<n && p[i]==p[st])
			++i;
		if ((i-st)&1)
			ok = false;
	}
	if (!ok)
	{
		puts("NO");
		return;
	}
	int St[1000100];
	int stpos=0;
	for (int i=n-1;i>=0;i--)
	{
		if (q[i])
		{
			ans[i] = -ans[i];
			St[stpos++] = ans[i];
		}
		else if (stpos)
		{
			q[i] = 1;
			if (St[stpos-1]==-ans[i])
			{
				--stpos;
			}
			else
			{
				ans[i]=-ans[i];
				St[stpos++]=ans[i];
			}
		}
	}
	if (stpos)
	{
		puts("NO");
		return;
	}
	rep(i,0,n)
		if (q[i]==0)
		{
			if (!stpos || St[stpos-1]!=ans[i])
				St[stpos++]=ans[i];
			else
			{
				ans[i]=-ans[i];
				--stpos;
			}
		}
	if (stpos)
	{
		puts("NO");
		return;
	}
	puts("YES");
	rep(i,0,n)
		printf("%d ",ans[i]);
	puts("");
	/*rep(n,2,21)
		go(n);*/
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