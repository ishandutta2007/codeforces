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
	int n,r;
	cin>>n>>r;
	if (n==1 && r==1)
	{
		puts("0\nT");
		return;
	}
	int res=1e9;
	pii ans;
	rep(i,1,r)
	{
		int u=i,d=r;
		int curr=0;
		int tot=0;
		while (u>1 && d>1)
		{
			int q=u/d;
			if (q>1) curr+=q-1;
			tot+=q;
			u-=d*q;
			swap(u,d);
		}
		if (min(u,d)==0) continue;
		tot+=max(u,d);
		curr+=max(0,max(u,d)-2);
		if (tot==n && curr<res)
		{
			res=curr;
			ans=pii(i,r);
		}
	}
	if (res==1e9)
		puts("IMPOSSIBLE");
	else
	{
		char str[1000001]={'T',0};
		int i=n-1;
		int u=ans.first,d=ans.second;
		char c='B';
		while (u!=1 && d!=1)
		{
			int q=u/d;
			u-=d*q;
			swap(u,d);
			int was=q;
			while (q--)
				str[i--]=c;
			c=(c=='T' ? 'B' : 'T');
		}
		rep(i,1,max(u,d))
			str[i]='B';
		if (c=='T')
			rep(i,max(u,d),n)
				if (str[i]=='T')
					str[i]='B';
				else
					str[i]='T';
		printf("%d\n%s\n",res,str);
	}

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