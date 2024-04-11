#pragma comment(linker,"/STACK:60777216")
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

int main()
{
	int n;
	cin>>n;
	int cnt4=-1;
	int sum=-1;
	for (int i=n/4;i>=0;i--)
	{
		if ((n-i*4)%7==0)
		{
			int cnt7=(n-i*4)/7;
			if (sum==-1 || (i+cnt7<sum || (i+cnt7==sum && i<cnt4)))
			{
				sum=i+cnt7;
				cnt4=i;
			}
		}
	}
	if (cnt4==-1) puts("-1");
	else
	{
		int cnt7=cnt7=(n-cnt4*4)/7;
		rep(i,0,cnt4) printf("4");
		rep(i,0,cnt7) printf("7");
		printf("\n");
	}
	return 0;
}

/*

*/