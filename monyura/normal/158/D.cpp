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
	int t[20001];
	cin>>n;
	int res=0;
	rep(i,0,n)
	{
		scanf("%d",t+i);
		res+=t[i];
	}
	int A[20001];
	rep(i,2,n)
		if (n%i==0 && 2*i!=n)
		{
			memset(A,0,sizeof(int)*n);
			rep(j,0,n)
				A[j%i]+=t[j];
			res=max(res,*max_element(A,A+i));
		}
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