#pragma comment(linker,"/STACK:32000000")
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
#define x first
#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

typedef pair<double,double> pdd;
double Eps=1e-9;

int main()
{
	int n,k;
	cin>>n>>k;
	int l=0,r=n,res=n;
	while (l<=r)
	{
		int c=(l+r)>>1;
		int curr=c;
		for (ll i=k;i<2e9;i*=k)
			curr+=c/i;
		if (curr>=n)
		{
			r=c-1;
			res=c;
		}
		else
			l=c+1;
	}
	cout<<res<<endl;
	return 0;
}

/*
4 0
1 2 3 4
*/