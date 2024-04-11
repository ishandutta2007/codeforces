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

int n , i;
char a[2010];

int main()
{
	cin >> a;
	n = strlen(a);
	for (i = 0 ; i < n ; i++) cout << a[i];
	for (i = 0 ; i < n ; i++) cout << a[n-i-1];
	cout << "\n";
	return 0;
}