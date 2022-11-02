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

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

pii getCoord(int x,int y,int a,int b)
{
	pii res;
	res.first=x-y;
	res.second=x+y;
	if (res.first<0) res.first=res.first/(2*b)-1;
	else res.first/=2*b;
	if (res.second<0) res.second=res.second/(2*a)-1;
	else res.second/=2*a;
	return res;
}
int main()
{
	int a,b;
	int x1,y1,x2,y2;
	cin>>a>>b>>x1>>y1>>x2>>y2;
	pii f=getCoord(x1,y1,a,b);
	pii s=getCoord(x2,y2,a,b);
	int dif=min(abs(f.first-s.first),abs(f.second-s.second));
	int res=abs(f.first-s.first)+abs(f.second-s.second)-dif;
	printf("%d\n",res);
	return 0;
} 
/*
2 4 3 -1 5 -2
*/