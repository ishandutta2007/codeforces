#pragma comment(linker,"/STACK:128000000")
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

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
#define x first
#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

int A[2000200];
//char B[2000200];
int P[1000100]={0};
int la,lb;
bool can(int l)
{
	int j=0;
	int last=0;
	int pos=0;
	for (int i=0;i<la;i++)
	{
		if (pos==0) 
		{
			last-=lb;
			pos=j;
		}
		if (j==0) last=0;
		for (;j<l;j++)
		{
			if (P[A[i+j]]==0) break;
			if (P[A[i+j]]>last)
			{
				last=P[A[i+j]];
				pos=j+1;
			}
			else if (P[A[i+j]]+lb>last && P[A[i+j]]<P[A[i]])
			{
				last=P[A[i+j]]+lb;
			}
			else break;
		}
		if (j==l) return true;
		if (j) j--;
		if (pos) pos--;
	}
	return false;
}

void run()
{
	cin>>la>>lb;
	rep(i,0,la)
		scanf("%d",A+i);
	rep(i,0,la)
		A[i+la]=A[i];
	rep(i,0,lb)
	{
		int a;
		scanf("%d",&a);
		P[a]=i+1;
	}
	int res=0;
	int j=0;
	int last=0;
	int pos=0;
	for (int i=0;i<la;i++)
	{
		if (pos==0) 
		{
			last-=lb;
			pos=j;
		}
		if (j==0) last=0;
		for (;j<la;j++)
		{
			if (P[A[i+j]]==0) break;
			if (P[A[i+j]]>last)
			{
				last=P[A[i+j]];
				pos=j+1;
			}
			else if (P[A[i+j]]+lb>last && P[A[i+j]]<P[A[i]])
			{
				last=P[A[i+j]]+lb;
			}
			else break;
		}
		movmax(res,j);
		if (j==la) break;
		if (j) j--;
		if (pos) pos--;
	}
	printf("%d\n",res);
}

int main()
{
#ifdef _MON_JUDGE_
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	time_t beg=clock();
	run();
#ifdef _MON_JUDGE_
	puts("=================");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/