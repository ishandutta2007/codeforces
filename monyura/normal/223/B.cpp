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


void run()
{
	char S[200200];
	char T[200200];
	scanf("%s %s",S,T);
	int A[200200];
	int B[200200];
	int a=0;
	int n=strlen(S);
	int m=strlen(T);
	rep(i,0,n)
	{
		if (a<m && S[i]==T[a])
			++a;
		B[i]=a-1;
	}
	int b=m-1;
	for (int i=n-1;i>=0;i--)
	{
		if (b>=0 && S[i]==T[b])
			--b;
		A[i]=b+1;
	}
	vector<int> Pos[30];
	rep(i,0,m)
		Pos[T[i]-'a'].push_back(i);
	rep(i,0,30)
		Pos[i].push_back(1e9);
	rep(i,0,n)
		if (*lower_bound(all(Pos[S[i]-'a']),A[i])>B[i])
		{
			printf("No\n");
			return;
		}
	printf("Yes\n");
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