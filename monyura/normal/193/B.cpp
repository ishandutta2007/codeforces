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

const ll INF=1e18;
int A[31],B[31],P[31];
ll K[31];
int Curr[31];
int Tmp[31];
ll best=-INF;
int n,u,r;
void rec(int step,int prev)
{
	if (((u-step)&1)==0)
	{
		ll curr=0;
		for (int i=0;i<n;++i)
			curr+=Curr[i]*K[i];
		if (curr>best)
			best=curr;
	}
	if (step>=u)
		return;
	if (prev!=0)
	{
		for (int i=0;i<n;++i)
			Curr[i]^=B[i];
		rec(step+1,0);
		for (int i=0;i<n;++i)
			Curr[i]^=B[i];
	}
	memcpy(Tmp,Curr,sizeof(int)*n);
	for (int i=0;i<n;++i)
		Curr[i]=Tmp[P[i]]+r;
	rec(step+1,1);
	memcpy(Tmp,Curr,sizeof(int)*n);
	for (int i=0;i<n;++i)
		Curr[P[i]]=Tmp[i]-r;
}

void run()
{
	
	cin>>n>>u>>r;
	rep(i,0,n)
		scanf("%d",A+i);
	rep(i,0,n)
		scanf("%d",B+i);
	rep(i,0,n)
		cin>>K[i];
	rep(i,0,n)
	{
		scanf("%d",P+i);
		--P[i];
	}
	memcpy(Curr,A,sizeof(int)*n);
	rec(0,-1);
	/*rep(i,1,u+1)
		if (((u-i)&1)==0)
		{
			fprintf(stderr,"%d\n",i);
			memcpy(Curr,A,sizeof(int)*n);
			rec(i,-1);
		}*/
	cout<<best<<endl;
}

void generate()
{
	int n=30,u=30,r=100;
	printf("%d %d %d\n",n,u,r);
	rep(i,0,n)
		printf("%d ",rand());
	puts("");
	rep(i,0,n)
		printf("%d ",rand());
	puts("");
	rep(i,0,n)
		printf("%d ",2*rand()-RAND_MAX);
	puts("");
	int P[31];
	rep(i,0,n)
		P[i]=i+1;
	random_shuffle(P,P+n);
	rep(i,0,n)
		printf("%d ",P[i]);
	puts("");
}

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t beg=clock();
#endif
	//generate();
    run();
#ifdef _MONYURA_
    printf("================\n");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/