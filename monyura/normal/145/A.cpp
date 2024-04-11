#pragma comment(linker,"/STACK:62000000")
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
template<class T> inline T SQR(T a){return a*a;}

int main()
{
	char a[100001];
	char b[100001];
	scanf("%s %s",a,b);
	int f=0,s=0;
	for (int i=0;a[i];i++)
		if (a[i]=='4' && b[i]=='7') ++f;
		else if (a[i]=='7' && b[i]=='4') ++s;
	cout<<max(f,s)<<endl;
	return 0;
} 

/*

*/