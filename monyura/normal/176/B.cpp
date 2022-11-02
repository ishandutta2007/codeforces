//#pragma comment(linker,"/STACK:128000000")
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

int M=1000000007;
void run()
{
	int D[100002][2];
	char A[2002],B[1001];
	int k;
	scanf("%s %s%d",A,B,&k);
	if (k==0)
	{
		if (strcmp(A,B)==0)
			printf("1\n");
		else
			printf("0\n");
		return;
	}
	int n=strlen(A);
	rep(i,0,n)
		A[n+i]=A[i];
	D[1][0]=0;
	D[1][1]=1;
	int S=n-1;
	rep(i,2,k+1)
	{
		D[i][0]=(S-D[i-1][0]+M)%M;
		D[i][1]=(S-D[i-1][1]+M)%M;
		S=(ll(n-1)*(D[i][1])+D[i][0])%M;
	}
	int res=0;
	rep(i,0,n)
		if (strncmp(A+i,B,n)==0)
			res=(res+D[k][i!=0])%M;
	cout<<res<<endl;


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