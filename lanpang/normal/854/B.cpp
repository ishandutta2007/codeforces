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
const int maxn = 5e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int a , b , c , d;

int main ()
{
	cin >> a >> b;
	if (b == 0) cout << "0 0\n";
	else
	{	
		if (a == b) c = 0;
		else c = 1;
		if (b > a/3) d = a-b;
		else d = b*2;
		cout << c << " " << d << "\n";
	}
	//system("PAUSE");
	return 0;
}