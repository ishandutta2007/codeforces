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

void run()
{
	int n;
	pii A[100100];
	map<int,int> has,can;
	vector<int> v;
	cin>>n;
	rep(i,0,n)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		has[a]++;
		if (a!=b)
			can[b]++;
		v.push_back(a);
		v.push_back(b);
	}
	sort(all(v));
	v.resize(unique(all(v))-v.begin());
	int res=1e9;
	int need=(n+1)/2;
	rep(i,0,v.size())
	{
		if (has[v[i]]+can[v[i]]>=need)
			res=min(res,need-has[v[i]]);
	}
	if (res<0) res=0;
	if (res==1e9) res=-1;
	printf("%d\n",res);
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