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
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}


int nod(int a,int b)
{
	int c=a;
	while (b)
	{
		c=b;
		b=a%b;
		a=c;
	}
	return c;
}

void run()
{
	int n;
	char A[1100];
	char B[1100];
	cin>>n;
	scanf(" %s %s",A,B);
	int l1=strlen(A);
	int l2=strlen(B);
	int nok=l1*l2/nod(l1,l2);
	char P1[3][5]={"RP","SR","PS"};
	char P2[3][5]={"PR","RS","SP"};
	int R[2]={0};
	rep(i,0,nok)
	{
		char a=A[i%l1];
		char b=B[i%l2];
		rep(j,0,3)
		{
			if (P1[j][0]==a && P1[j][1]==b)
			{
				R[0]++;
				break;
			}
			if (P2[j][0]==a && P2[j][1]==b)
			{
				R[1]++;
				break;
			}
		}
	}
	rep(i,0,2)
		R[i]*=n/nok;
	rep(i,0,n%nok)
	{
		char a=A[i%l1];
		char b=B[i%l2];
		rep(j,0,3)
		{
			if (P1[j][0]==a && P1[j][1]==b)
			{
				R[0]++;
				break;
			}
			if (P2[j][0]==a && P2[j][1]==b)
			{
				R[1]++;
				break;
			}
		}
	}
	rep(i,0,2)
		printf("%d ",R[i]);

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