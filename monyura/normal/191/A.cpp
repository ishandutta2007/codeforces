#pragma comment(linker,"/STACK:64000000")
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
	int n;
	cin>>n;
	int D[26][26]={0};
	int INF=-1e9;
	rep(i,0,26)
		rep(j,0,26)
			if (i!=j)
				D[i][j]=INF;
	int Curr[26];
	char str[100];
	rep(i,0,n)
	{
		scanf(" %s",str);
		int l=strlen(str);
		rep(i,0,26)
			Curr[i]=max(D[i][str[l-1]-'a'],D[i][str[0]-'a']+l);
		rep(i,0,26)
			D[i][str[l-1]-'a']=Curr[i];
	}
	int res=D[0][0];
	rep(i,1,26)
		movmax(res,D[i][i]);
	if (res==INF) res=0;
	cout<<res<<endl;
}

int main()
{
#ifdef _MONYURA_
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
//#else
//		freopen(F_NAME".in","r",stdin);
//		freopen(F_NAME".out","w",stdout);
#endif
	time_t beg=clock();
	run();
	fprintf(stderr,"Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
	return 0;
}

/*

*/