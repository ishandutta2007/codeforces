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

void run()
{
	int A[4][4];
	int n;
	cin>>n;
	int B[16];
	rep(i,0,n*n)
		scanf("%d",B+i);
	int nsq=n*n;
	sort(B,B+nsq);
	int S[4],G[4];
	do
	{
		memset(S,0,16);
		rep(i,0,n)
			rep(j,0,n)
				S[i]+=B[i*n+j];
		bool ok=1;
		rep(i,1,n)
			if (S[i]!=S[0]) ok=0;
		if (!ok) continue;
		memset(G,0,16);
		rep(j,0,n)
			rep(i,0,n)
				G[j]+=B[i*n+j];
		if (S[0]!=G[0])
			continue;
		rep(i,1,n)
			if (G[i]!=G[0]) ok=0;
		int d=0;
		rep(i,0,n)
			d+=B[i*n+i];
		if (d!=S[0]) continue;
		d=0;
		rep(i,0,n)
			d+=B[i*n+n-i-1];
		if (d!=S[0]) continue;
		if (ok)
		{
			printf("%d\n",S[0]);
			rep(i,0,n)
				rep(j,0,n)
				{
					printf("%d",B[i*n+j]);
					if (j!=n-1) putchar(' ');
					else putchar('\n');
				}
			return;
		}
	}
	while (next_permutation(B,B+nsq));
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