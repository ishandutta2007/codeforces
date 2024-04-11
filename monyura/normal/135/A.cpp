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


int main()
{
	int n;
	cin>>n;
	int A[100001];
	rep(i,0,n)
		scanf("%d",A+i);
	sort(A,A+n);
	if (A[0]==A[n-1] && A[0]==1)
		A[n-1]=2;
	else
	{
		A[n-1]=1;
		sort(A,A+n);
	}
	rep(i,0,n)
		printf("%d ",A[i]);
	return 0;
} 
/*
a b c d e f g b
b a c a c b c
*/