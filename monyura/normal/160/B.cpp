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
	char A[500];
	scanf(" %s",A);
	sort(A,A+n,greater<char>());
	sort(A+n,A+2*n,greater<char>());
	bool men=1,bol=1;
	rep(i,0,n)
		if (A[i]<A[i+n]) bol=0;
		else if (A[i]>A[i+n]) men=0;
		else men=bol=0;
	if (men || bol) puts("YES");
	else puts("NO");
	return 0;
} 

/*


*/