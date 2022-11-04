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

int n;

int main ()
{
	cin >> n;
	if (n % 10 <= 4) cout << n/10*10 << "\n";
	else cout << (n/10+1)*10 << "\n";
	//system("PAUSE");
	return 0;
}