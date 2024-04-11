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
	ll n,curr;
	cin>>n;
	n--;
	curr=5;
	int cnt=1;
	while (curr<=n) 
	{
		n-=curr;	
		cnt<<=1;
		curr<<=1;
	}
	int r=n/cnt;
	char str[10][10]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
	printf("%s\n",str[r]);
	return 0;
}
/*

*/