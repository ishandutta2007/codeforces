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
	int A[101];
	rep(i,0,n)
		scanf("%d",A+i);
	sort(A,A+n,greater<int>());
	int S=0;
	rep(i,0,n)
		S+=A[i];
	int res=0;
	int R=0;
	rep(i,0,n)
	{
		if (R+A[i]>S-A[i])
		{
			res=i+1;
			break;
		}
		R+=A[i];
		S-=A[i];
	}
	cout<<res<<endl;
	return 0;
} 

/*


*/