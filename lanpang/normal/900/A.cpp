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

int x , y , n , xx , yy , i;

int main ()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d%d",&x,&y);
		if (x > 0) xx++;
		else yy++; 
	}
	if (xx >= n-1 || yy >= n-1) cout << "Yes\n";
	else cout << "No\n"; 
	//system("PAUSE");
	return 0;
}