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

int n , k , a[maxn] , i , maa , mia;

int main ()
{
	cin >> n >> k;
	maa = -mod;
	mia = mod;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		mia = min(mia,a[i]);
		maa = max(maa,a[i]); 
	}
	if (k > 1) 
	{
		if (k > 2) cout << maa << "\n";
		else cout << max(a[1],a[n]) << "\n";
	}
	else cout << mia << "\n"; 
	//system("PAUSE");
	return 0;
}