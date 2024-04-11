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
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define x first
#define y second

const double PI=acos(-1.0);

int main()
{
	int n;
	cin>>n;
	int c[5]={0};
	rep(i,0,n)
	{
		int a;
		scanf("%d",&a);
		++c[a];
	}
	int res=c[4]+c[2]/2;
	c[2]&=1;
	res+=c[3];
	c[1]-=min(c[1],c[3]);
	res+=(c[1]+2*c[2])/4+((c[1]+2*c[2])%4!=0);
	printf("%d\n",res);
	return 0;
} 

/*
1
1

1
2

1
3

1
4


*/