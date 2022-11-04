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

LL a , b , c , x , y , xx , yy;

int main ()
{
	cin >> xx >> yy >> a >> b >> c;
	x = a*2+b;
	y = c*3+b;
	cout << max((LL)0,x-xx)+max((LL)0,y-yy) << "\n";
	//system("PAUSE");
	return 0;
}