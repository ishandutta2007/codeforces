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
	int n,k;
	cin>>n>>k;
	int A[51];
	rep(i,0,n)
		scanf("%d",A+i);
	rep(i,k,n)
		if (A[i]!=A[i-1]) break;
		else ++k;
	while (k>0 && A[k-1]==0) --k;
	printf("%d\n",k);
	return 0;
} 

/*



*/