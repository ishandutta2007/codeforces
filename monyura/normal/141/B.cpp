//#pragma comment(linker,"/STACK:32000000")
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
	int a,x,y;
	cin>>a>>x>>y;
	double X[3]={-a/2.0,-a,0};
	int res=-1;
	if (x>X[0] && x<X[0]+a && y>0 && y<a)
		res=1;
	int cy=a;
	rep(i,0,4e6+2)
	{
		int cx=X[i%3];
		if (x>cx && x<cx+a && y>cy && y<cy+a)
		{
			res=i+2;
			break;
		}
		if (i%3!=1) cy+=a;
	}
	printf("%d\n",res);
	return 0;
} 

/*
4 4
1 2 -10 3
1 3 1 -10
2 4 -10 -4
3 4 0 -3
*/