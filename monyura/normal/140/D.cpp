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
	int n;
	cin>>n;
	int A[100];
	rep(i,0,n)
		scanf("%d",A+i);
	sort(A,A+n);
	int z=0,v=0;
	int curr=10;
	rep(i,0,n)
		if (curr+A[i]<=720)
		{
			z++;
			curr+=A[i];
			if (curr>360)
				v+=curr-360;
		}
	printf("%d %d\n",z,v);
	return 0;
} 

/*
9
1 2 3 3 3 3 3 3 3 
*/