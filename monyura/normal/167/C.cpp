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

bool win(ll a,ll b)
{
	if (a==0 || b==0) return false;
	if (a<b) swap(a,b);
	if (a%b==0) return true;
	if (!win(b,a%b))
		return true;
	a=(a-a%b)-1;
	if (b&1)
		return a%(2*b)>=b;
	if (double(b)*b<3e18)
		a%=b*(b+1);
	if (double(b)*b>3e18 || a<b*b)
		return a%(2*b)>=b;
	return true;

}


void run()
{
	int t;
	cin>>t;
	rep(i,0,t)
	{
		ll a,b;
		cin>>a>>b;
		puts(win(a,b)?"First":"Second");
	}
	
}

int main()
{
	//int a;
	//while (cin>>a)
	//{
	//	bool A[1001]={1,0};
	//	rep(i,1,1001)
	//	{
	//		int curr=a;
	//		bool win=0;
	//		while (i-curr>=0)
	//		{
	//			if (A[i-curr]==0)
	//				win=1;
	//			curr*=a;
	//		}
	//		A[i]=win;
	//	}
	//	/*rep(i,0,20)
	//		printf("%d) %d\n",i,A[i]);*/
	//	rep(i,1,1001)
	//	{
	//		int b=a;
	//		int c=i-1;
	//		int res=-1;
	//		if (b&1)
	//			res=(c%(2*b)>=b);
	//		else
	//		{
	//			if (double(b)*b<3e18)
	//				c%=b*(b+1);
	//			if (c<b*b)
	//				res=(c%(2*b)>=b);
	//			else
	//				res=1;
	//		}
	//		if (res!=A[i])
	//		{
	//			printf("%d ",i);
	//		}
	//	}
	//}
#ifdef _MON_JUDGE_
	freopen("test.txt","r",stdin);
	freopen("res.txt","w",stdout);
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