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
const int maxn = 5e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , i , k , mk;

int main ()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a+1,a+n+1);
	mk = 1;
	for (i = 1 ; i <= n ; i++)
	{
		k = 1;
		while (i < n && a[i] == a[i+1])
		{
			i++;
			k++;
		}
		mk = max(mk,k);
	}
	cout << mk << "\n";
	//system("PAUSE");
	return 0;
}