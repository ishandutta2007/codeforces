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

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int m;
int dist(int from,int to,bool &up)
{
	if (from==to) return 0;
	if (from<to)
	{
		if (up)
			return to-from;
		else
		{
			up=!up;
			return from+to;
		}
	}
	if (up)
	{
		up=!up;
		return m-from-1+m-1-to;
	}
	else
		return from-to;
}

int main()
{
	int n;
	cin>>n>>m;
	rep(i,0,n)
	{
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		a--;
		b--;
		if (a==b)
		{
			cout<<t<<endl;
			continue;
		}
		int pos=(t)%(2*m-2);
		bool up=1;
		if (pos>=m)
		{
			pos=m-1-(pos-m+1);
			up=0;
		}
		int add=dist(pos,a,up);
		pos=a;
		add+=dist(pos,b,up);
		printf("%d\n",t+add);
	}
	return 0;
}


/*
5 5
1 5 4
1 3 1
1 3 4
3 1 5
4 2 5

5 5
3 1 5
4 2 5

5 4
1 2 6

*/