#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int main ()
{
	long long ax , ay , bx , by , cx , cy , a , b , c , d;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	a = bx-ax;
	b = by-ay;
	c = cx-bx;
	d = cy-by;
	if ((a*a+b*b != c*c+d*d)||(b*c == a*d)) cout << "No\n";
	else cout << "Yes\n";
	//system("PAUSE");
	return 0;
}