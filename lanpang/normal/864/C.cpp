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
const int maxn = 1e4+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL a , b , f , k , i , l[2] , p[maxn] , ans , gg;

int main()
{
	cin >> a >> b >> f >> k;
	l[1] = f*2;
	l[0] = (a-f)*2;
	p[0] = 0;
	p[1] = f;
	for (i = 2 ; i <= k ; i++) p[i] = l[i%2];
	l[0] = f;
	l[1] = a-f;
	p[k+1] = l[k%2];
	for (i = 1 ; i <= k+1 ; i++) p[i] += p[i-1];
	gg = b;
	for (i = 1 ; i <= k+1 ; i++)
	{
		gg -= p[i]-p[i-1];
		if (gg < 0) 
		{
			ans = -1;
			break;
		}
		if (i <= k && gg < p[i+1]-p[i]) 
		{
			ans++;
			gg = b;
		}
	}
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}