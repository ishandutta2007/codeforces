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
	int n;
	cin>>n;
	typedef pair<int,string> pic;
	pic A[3001];
	char str[100];
	rep(i,0,n)
	{
		int a;
		scanf(" %s%d",str,&a);
		A[i]=pic(a,str);
	}
	sort(A,A+n);
	int H[3002];
	bool ok=true;
	int curr=1;
	int C[3002];
	rep(i,0,n)
	{
		if (A[i].first>i)
		{
			ok=false;
			break;
		}
		if (i==0) H[i]=1;
		else
		{
			memcpy(C,H,sizeof(int)*i);
			sort(C,C+i,greater<int>());
			H[i]=C[A[i].first]+1;
			rep(j,0,i)
				if (H[j]>=H[i])
					H[j]++;
		}
	}
	if (ok)
		rep(i,0,n)
			printf("%s %d\n",A[i].second.c_str(),H[i]);
	else
		printf("-1\n");
	return 0;
} 

/*
4
a 0
b 0
c 0
d 0

*/