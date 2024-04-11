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


int Days[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int Sum[13];
int toSec(int m,int d,int hh,int mm,int sec)
{
	int res=(Sum[m] + d-1)*24*60*60;
	res+=hh*60*60 + mm*60 + sec;
	return res;
}

//int A[500100];
//int T[500100];
//char str[5000100];

int C[5002][5002]={0};
int S[5002][5002]={0};

void run()
{
	//int A[200]={0};
	//int n;
	//cin>>n;
	//if (n<=2)
	//{
	//	puts("-1");
	//	return;
	//}
	//rep(i,1,n+1)
	//	scanf("%d",A+i);
	//int res=0;
	//for (int i=n;i>0;i--)
	//{
	//	res+=A[i];
	//	A[i-1]=max(0,A[i-1]-A[i]);
	//	A[i/2]=max(0,A[i/2]-A[i]);
	//	A[i]=0;
	//}
	//rep(i,1,n+1)
	//{
	//	res+=A[i];
	//	A[i]=0;
	//}
	//cout<<res<<endl;
	char str[5002];
	scanf("%s",str);
	int n=strlen(str);
	rep(i,0,n)
	{
		int m=0;
		while (i-m>=0 && i+m<n && str[i-m]==str[i+m])
		{
			C[i-m+1][i+m+1]++;
			++m;
		}
		m=0;
		while (i-m>=0 && i+m+1<n && str[i-m]==str[i+m+1])
		{
			C[i-m+1][i+m+2]++;
			++m;
		}
	}
	rep(i,1,n+1)
		rep(j,1,n+1)
			S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1] + C[i][j];
	int q;
	cin>>q;
	rep(i,0,q)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int res = S[r][r] - S[l-1][r] - S[r][l-1] + S[l-1][l-1];
		printf("%d\n",res);
	}
}


int main()
{
	srand(time(0));
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

*/