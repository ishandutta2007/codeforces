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
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	if (m==1)
	{
		puts("1");
		return 0;
	}
	int i1=(a-1)/m,j1=(a-1)%m;
	int i2=(b-1)/m,j2=(b-1)%m;
	if (b==n) j2=m-1;
	int res;
	if (i2-i1>1)
	{
		res=3;
		if (j1-1==j2) res=2;
		else 
		{
			if (j1==0) res--;
			if (j2==m-1) res--;
		}
	}
	else if (i2-i1==1)
	{
		res=2;
		if (j1==0 && j2==m-1) res=1;
	}
	else
		res=1;
	cout<<res<<endl;
    return 0;      
}
/*
8 3 1 8
*/