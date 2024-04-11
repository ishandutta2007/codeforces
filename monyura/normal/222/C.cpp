#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

const int SZ=1e7+1;
int pr[1000000];
int st[SZ]={0};
int prCnt=0;
int del[SZ]={0};

void run()
{
	rep(i,2,SZ)
	{
		if (del[i]==0)
		{
			del[i]=i;
			pr[prCnt++]=i;
		}
		for (int j=0;j<prCnt && pr[j]<=del[i] && i*pr[j]<SZ;j++)
			del[i*pr[j]]=pr[j];
	}
	int n,m;
	cin>>n>>m;
	int A[100100];
	int B[100100];
	rep(i,0,n)
	{
		int a;
		scanf("%d",&a);
		A[i]=a;
		while (a!=1)
		{
			st[del[a]]++;
			a/=del[a];
		}
		
	}
	rep(i,0,m)
	{
		int b;
		scanf("%d",&b);
		B[i]=b;
		while (b!=1)
		{
			st[del[b]]--;
			b/=del[b];
		}
		
	}
	vector<int> nom;
	vector<int> denom;
	rep(i,0,n)
	{
		int a=A[i];
		int curr=1;
		while (a!=1)
		{
			if (st[del[a]]>0)
			{
				curr*=del[a];
				--st[del[a]];
			}
			a/=del[a];
		}
		nom.push_back(curr);
	}
	rep(i,0,m)
	{
		int b=B[i];
		int curr=1;
		while (b!=1)
		{
			if (st[del[b]]<0)
			{
				curr*=del[b];
				++st[del[b]];
			}
			b/=del[b];
		}
		denom.push_back(curr);
	}
	printf("%d %d\n",nom.size(),denom.size());
	rep(i,0,nom.size())
		printf("%d ",nom[i]);
	puts("");
	rep(i,0,denom.size())
		printf("%d ",denom[i]);
	puts("");


}

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t beg=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("================\n");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/