#pragma comment(linker,"/STACK:16777216")
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

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int main()
{
	int n;
	cin>>n;
	int *A=new int[n];
	rep(i,0,n)
		scanf("%d",A+i);
	ll res=0;
	int curr=1;
	rep(i,1,n)
		if (A[i]==A[i-1]) curr++;
		else
		{
			res+=(curr*ll(curr+1))>>1;
			curr=1;
		}
	res+=(curr*ll(curr+1))>>1;
	cout<<res<<endl;
	return 0;
}

/*

*/