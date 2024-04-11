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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a , b , m;

int main ()
{
	int i;
	cin >> n >> a >> b;
	for (i = 1 ; i < n ; i++)
	{
		m = max(m,min(a/i,b/(n-i)));
	}
	cout << m << "\n";
	//system("PAUSE");
	return 0;
}