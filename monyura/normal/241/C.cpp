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


int getScore(int S[2][101],pii A[2][101],int N[2],int st,int x0,int y0,int hr)
{
	int res=0;
	int x1=100000;
	rep(k,1,N[0]+N[1]+2)
	{
		int p=st;
		int curr=0;
		int y=100;
		int y1=100*k;
		if (k&1) 
			y1+=100-hr;
		else 
			y1+=hr;
		bool allOk=1;
		bool B[2][101]={0};
		rep(l,0,k)
		{
			ll y10=y1-y0;
			ll x10=x1-x0;
			ll sr=x10*(y-y0);
			bool ok=0;
			rep(j,0,N[p])
				if (y10*A[p][j].first<=sr && sr<=A[p][j].second*y10 && !B[p][j])
				{
					B[p][j]=1;
					curr+=S[p][j];
					ok=1;
					break;
				}
			if (!ok)
			{
				allOk=0;
				break;
			}
			y+=100;
			p^=1;
		}
		if (allOk)
			res=max(res,curr);
	}
	return res;
}

void run()
{
	int hl,hr,n;
	cin>>hl>>hr>>n;
	int S[2][101]={0};
	pii A[2][101];
	char str[101];
	int N[2]={0};
	rep(i,0,n)
	{
		int d,a,b;
		scanf("%d%s%d%d",&d,str,&a,&b);
		int p=str[0]=='T';
		S[p][N[p]]=d;
		A[p][N[p]]=pii(a,b);
		N[p]++;
	}
	int res=0;
	int c=getScore(S,A,N,1,0,hl,hr);
	res=max(res,c);
	c=getScore(S,A,N,0,0,100-hl,100-hr);
	res=max(res,c);
	cout<<res<<endl;
}


int main()
{
	srand(time(0));
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
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