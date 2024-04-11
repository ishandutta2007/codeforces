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

typedef unsigned long long ll;
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

ll S[200100][26]={0};

double calc(char *A,char *B,ll denum,bool rev)
{
	int n=strlen(A);
	rep(i,0,n)
		rep(j,0,26)
			if (j==B[i]-'A')
				S[i][j]=(i==0 ? 0 : S[i-1][j]) + i+1;
			else
				S[i][j]=(i==0 ? 0 : S[i-1][j]);
	double res=0;
	rep(i,0,n)
	{
		ll curr=S[i][A[i]-'A']*(n-i);
		if (rev)
		{
			if (i==0)
				curr=0;
			else
				curr=S[i-1][A[i]-'A']*(n-i);
		}
		res+=curr/double(denum);
	}
	return res;
}

void run()
{
	int n;
	char A[200100],B[200100];
	cin>>n;
	scanf("%s %s",A,B);
	ll denum=0;
	rep(i,1,n+1)
		denum+=ll(i)*i;
	double r1=calc(A,B,denum,false);
	double r2=calc(B,A,denum,true);
	double res=r1+r2;
	printf("%.7lf\n",res);
	
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