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
	rep(i,0,2*n+1)
	{
		char str[100];
		memset(str,' ',100);
		rep(j,0,min(i+1,2*n+1-i))
		{
			str[n-j]=ej-1-j+'0';
			str[n+j]=ej-1-j+'0';
		}
		char cnt=0;
		rep(j,0,2*n+1)
		{
			printf("%c",str[j]);
			if (str[j]=='0')
				cnt++;
			if (cnt>1 || (cnt!=0 && (i==0 || i==2*n))) break;
			else printf(" ");

		}
		printf("\n");

	}

	return 0;
}
/*

*/