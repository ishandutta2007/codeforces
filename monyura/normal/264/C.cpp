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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double PI=acos(-1.0);

typedef pair<pli,pli> pp;

pp update(const pp &p,const pli &a)
{
	pp res=p;
	if (res.first.second==a.second && res.first.first<=a.first)
		res.first=a;
	else if (res.second.second==a.second && res.second.second<a.first)
		res.second=a;
	else 
	{
		if (p.first.first<=a.first)
		{
			res.first = a;
			res.second = p.first;
		}
		else if (p.second.first<=a.first)
		{
			res.first = p.first;
			res.second = a;
		}
	}
	if (res.first.first<res.second.first)
		swap(res.first,res.second);
	return res;
}

pli getCurr(const pp &a,int col)
{
	if (a.first.second==col)
		return a.second;
	return a.first;
}

const ll INF=1e17;
ll Score[100100];
ll getRes(int *V,int *C,int n,ll a,ll b)
{
	pp mx(pli(0,-1),pli(0,-1));
	rep(i,0,n)
		Score[i]=-INF;
	Score[C[0]]=V[0]*b;
	mx=update(mx,pli(Score[C[0]],C[0]));
	rep(i,1,n)
	{
		ll same = Score[C[i]] + V[i]*a;
		pli curr = getCurr(mx,C[i]);
		ll dif = curr.first + V[i]*b;
		Score[C[i]]=max(Score[C[i]],max(same,dif));
		mx=update(mx,pli(Score[C[i]],C[i]));
	}
	return mx.first.first;
}

ll getBF(int *V,int *C,int n,ll a,ll b)
{
	ll S[100][100];
	rep(i,0,n)
		S[0][i]=-INF;
	S[0][C[0]]=V[0]*b;
	rep(i,1,n)
	{
		ll mx=0;
		rep(j,0,n)
			if (j!=C[i])
			{
				mx=max(mx,S[i-1][j]);
				S[i][j]=S[i-1][j];
			}
		S[i][C[i]] = max(S[i-1][C[i]],max(mx + V[i]*b,S[i-1][C[i]]+V[i]*a));
	}
	ll res=0;
	rep(i,0,n)
		res=max(res,S[n-1][i]);
	return res;
}

void run()
{
	int n,q;
	int V[100100];
	int C[100100];
	cin>>n>>q;
	rep(i,0,n)
		scanf("%d",V+i);
	rep(i,0,n)
	{
		scanf("%d",C+i);
		C[i]--;
	}
	rep(i,0,q)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		ll res=getRes(V,C,n,a,b);
		cout<<res<<endl;
		//ll r2 = getBF(V,C,n,a,b);
		//cout<<res<<' '<<r2<<endl;
	}

	//srand(time(0));
	//rep(i,0,1000)
	//{
	//	n=rand()%20+1;
	//	rep(j,0,n)
	//		V[j]=rand()%100 - 50;
	//	rep(j,0,n)
	//		C[j]=rand()%n;
	//	q=rand()%20+1;
	//	rep(j,0,q)
	//	{
	//		int a=rand()%100-50;
	//		int b = rand()%100 - 50;
	//		ll r1=getRes(V,C,n,a,b);
	//		ll r2=getBF(V,C,n,a,b);
	//		if (r1!=r2)
	//		{
	//			printf("ERROR\n");
	//			printf("%d 1\n",n);
	//			rep(j,0,n)
	//				printf("%d ",V[j]);
	//			puts("");
	//			rep(j,0,n)
	//				printf("%d ",C[j]);
	//			puts("");
	//			printf("%d %d\n",a,b);
	//			cout<<r1<<' '<<r2<<"\n\n";
	//			
	//		}
	//	}

	//}

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