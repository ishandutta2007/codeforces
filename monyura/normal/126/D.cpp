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

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int main()
{
	int t;
	cin>>t;
	ll F[100];
	int cnt=2;
	F[0]=1;
	F[1]=2;
	while (ull(F[cnt-1]+F[cnt-2])<=1e18)
	{
		F[cnt]=F[cnt-1]+F[cnt-2];
		cnt++;
	}
	int du[100],dn[100];
	char S[100];
	rep(i,0,t)
	{
		ll n;
		scanf("%lld",&n);
		memset(du,0,400);
		memset(dn,0,400);
		memset(S,0,100);
		int pos=cnt-1;
		while (n>0)
		{
			while (F[pos]>n) pos--;
			n-=F[pos];
			S[pos]=1;
		}
		int l=-1;
		rep(j,0,cnt)
			if (S[j]==1)
			{
				if (l==-1)
				{
					du[j]=((j+2)/2)-1;
					dn[j]=1;
				}
				else
				{
					du[j]=((j-l+1)/2-1)*(du[l]+dn[l]);
					if (((j-l)&1)==0 )
						du[j]+=du[l];
					dn[j]=du[l]+dn[l];
				}
				l=j;
			}
		printf("%d\n",du[l]+dn[l]);
	}
    return 0;
} 
/*
4
(()
)()
((())
)()

4
(((
)))((
))(
)

3
()
(()
)

3
((
)(
))

7
(())
)((((
)))(
(
)
))))(
)(((

3
(((((
))))
)))((
*/