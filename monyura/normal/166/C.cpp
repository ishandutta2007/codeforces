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


int main()
{
	int n,x;
	cin>>n>>x; 
	int A[501];
	rep(i,0,n)
		scanf("%d",A+i);
	sort(A,A+n);
	bool ok=0;
	rep(i,0,n)
		if (A[i]==x)
			ok=1;
	int res=0;
	if (!ok)
	{
		A[n++]=x;
		res=1;
	}
	sort(A,A+n);
	int d=1e9;
	int t=0;
	rep(i,1,n+1)
		if (A[i-1]==x)
		{
			int a=abs(i-(n+1)/2);
			if (a<d)
			{
				t=i-(n+1)/2;
				d=a;
			}
		}
	if (d!=0)
		res+=d*2-((n&1)==(t<0));
	
	cout<<res<<endl;
	return 0;
}

/*
2 2
1 2
*/