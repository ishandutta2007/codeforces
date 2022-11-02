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

int A[500100];
//int T[500100];
char str[5000100];


void run()
{
	/*int A[200]={0};
	int n;
	cin>>n;
	if (n<=2)
	{
		puts("-1");
		return;
	}
	rep(i,1,n+1)
		scanf("%d",A+i);
	int res=0;
	for (int i=n;i>0;i--)
	{
		res+=A[i];
		int ind=i^1;
		A[ind]=max(0,A[ind]-A[i]);
		A[i/2]=max(0,A[i/2]-A[i]);
		A[i]=0;
	}
	rep(i,1,n+1)
	{
		res+=A[i];
		A[i]=0;
	}
	cout<<res<<endl;*/
	rep(i,0,12)
		Sum[i+1]=Sum[i]+Days[i];
	int n,cnt;
	cin>>n>>cnt;
	int pos=0;
	int st=0;
	for (int i=0; ;i++)
	{
		int y,d,m;
		if (scanf("%d-%d-%d",&y,&m,&d)<=0)
			break;
		int hh,mm,sec;
		scanf("%d:%d:%d",&hh,&mm,&sec);
		gets(str);
		
		int tm=toSec(m-1,d,hh,mm,sec);
		A[i]=tm;
		int *pos=lower_bound(A,A+i,tm-n+1);
		if (A+i-pos+1>=cnt)
		{
			printf("2012-%.2d-%.2d %.2d:%.2d:%.2d\n",m,d,hh,mm,sec);
			return;
		}
		/*if (pos!=0 && tm==T[pos-1])
			A[pos-1]++;
		else
		{
			T[pos]=tm;
			A[pos++]=1;
		}
		if (i>=cnt-1)
		{
			if (tm-T[st]<n)
			{
				printf("2012-%.2d-%.2d %.2d:%.2d:%.2d\n",m,d,hh,mm,sec);
				return;
			}
			A[st]--;
			if (A[st]==0)
				++st;
		}*/
		
	}
	puts("-1");
	
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