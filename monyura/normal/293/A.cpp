#pragma comment(linker,"/STACK:65000000")
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
#include <assert.h>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const double PI = acos(-1.0);

void run()
{
	char A[2000100];
	char B[2000100];
	int n;
	cin>>n;
	n*=2;
	scanf("%s%s",A,B);
	int p = 0;
	rep(i,0,n)
		p+= A[i]==B[i] && A[i]=='1';
	int cnt1 = (p+1)/2;
	int cnt2 = p - cnt1;
	int a=0,b=0;
	p&=1;
	rep(i,0,n)
		if (A[i]!=B[i])
		{
			a+=A[i]=='1';
			b+=B[i]=='1';
		}
	int c = min(a,b);
	a-=c;
	b-=c;
	if (a!=0)
		cnt1+=(a+(!p))/2;
	else
		cnt2+=(b+p)/2;
	if (cnt1>cnt2)
		puts("First");
	else if (cnt1<cnt2)
		puts("Second");
	else
		puts("Draw");
}


int main()
{
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(name".in","r",stdin);
	//freopen(name".out","w",stdout);
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