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


ll getCnt(ll a)
{
	if (a<10) return a+1;
	ll res=10;
	ll ten=10;
	int l=0;
	while (ten*10<=a)
	{
		res+=9*ten/10;
		ten*=10;
	}
	int f=a/ten;
	res+=(f-1)*ten/10;
	a%=ten;
	ten/=10;
	while (a>=10)
	{
		res+=(a/ten)*ten/10;
		a%=ten;
		ten/=10;
		
	}
	res+=(a>=f);
	return res;

	
}

void run()
{
	ll l,r;
	cin>>l>>r;
	ll a=getCnt(r);
	ll b=getCnt(l-1);
	ll res=a-b;
	cout<<res<<endl;
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