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
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<ll,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double PI=acos(-1.0);


void run()
{
	int n;
	cin>>n;
	int A[100100];
	int Pos[100100];
	memset(Pos,-1,sizeof(Pos));
	rep(i,0,n)
		scanf("%d",A+i);
	int D[100100]={0};
	int Pr[100100]={0};
	rep(i,0,n)
	{
		int pos=0;
		int a=A[i];
		for (int i=2;i*i<=a;i++)
			if (a%i==0)
			{
				Pr[pos++]=i;
				while (a%i==0)
					a/=i;
			}
		if (a!=1)
			Pr[pos++]=a;
		int curr=1;
		rep(j,0,pos)
		{
			if (Pos[Pr[j]]!=-1)
				curr=max(curr,D[Pos[Pr[j]]]+1);
			Pos[Pr[j]]=i;
		}
		D[i]=curr;
	}
	int res=*max_element(D,D+n);
	cout<<res<<endl;
}



int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("barns.in","r",stdin);
	//freopen("barns.out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*
10 10 92
11 10 92
*/