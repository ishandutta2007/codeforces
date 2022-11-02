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


const int SZ=1e6+1;
int del[SZ];
int pr[100100];
int cnt=0;
int Cnt[SZ]={0};
int D[SZ]={0};

void run()
{
	D[1]=1;
	rep(i,2,SZ)
	{
		if (del[i]==0)
		{
			del[i]=i;
			pr[cnt++]=i;
			Cnt[i]=1;
			D[i]=2;
		}
		else
		{
			if (del[i/del[i]]==del[i])
				Cnt[i]=Cnt[i/del[i]]+1;
			else
				Cnt[i]=1;
			D[i]=D[i/del[i]]/Cnt[i]*(Cnt[i]+1);
		}
		
		for (int j=0;j<cnt && pr[j]<=del[i] && pr[j]*ll(i)<SZ;j++)
			del[pr[j]*i]=pr[j];
	}
	int a,b,c;
	cin>>a>>b>>c;
	int s=0;
	rep(i,1,a+1)
		rep(j,1,b+1)
			rep(k,1,c+1)
				s+=D[i*j*k];
	s&=(1<<30)-1;
	cout<<s<<endl;
}


int main()
{
	srand(time(0));
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen("final.in","r",stdin);
	//freopen("final.out","w",stdout);
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