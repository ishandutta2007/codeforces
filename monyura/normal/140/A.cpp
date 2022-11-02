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
	int n,R,r;
	cin>>n>>R>>r;
	if (r>R)
	{
		puts("NO");
		return 0;
	}
	if (n==1)
		puts("YES");
	else if (n==2)
	{
		if (2*r<=R)
			puts("YES");
		else
			puts("NO");
	}
	else
	{
		if ((R-r)*sin(PI/n)+1e-7<r)
			puts("NO");
		else 
			puts("YES");
	}
	return 0;
} 

/*
100
*/