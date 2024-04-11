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

char str[100100];
char Ans[100100];

void run()
{
	int n;
	scanf("%s",str);
	vector<int> V[30];
	rep(i,0,strlen(str))
		V[str[i]-'a'].push_back(i);
	int cnt=0;
	int last=-1;
	for (int i='z'-'a';i>=0;i--)
		rep(j,0,V[i].size())
			if (V[i][j]>last)
			{
				Ans[cnt++]=i+'a';
				last=V[i][j];
			}
	printf("%s\n",Ans);
}

int main()
{
#ifdef _MONYURA_
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
#endif
	time_t beg=clock();
	run();
#ifdef _MONYURA_
	printf("================\n");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/