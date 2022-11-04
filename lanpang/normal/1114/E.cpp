#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , l , r , m , ret , tp , cnt , gcd , i;

int main()
{
	cin >> n;
	l = 1;
	r = 1000000000;
	while (l <= r)
	{
		m = (l+r)/2;
		cout << "> " << m << endl;
		cnt++;
		cin >> ret;
		if (ret == 1) l = m+1;
		else r = m-1;
	}
	tp = l;
	for (i = 1 ; i <= 60-cnt ; i++)
	{
		cout << "? " << rand()*rand()%n+1 << endl;
		cin >> ret;
		if (tp > ret)
		{
			if (gcd == 0) gcd = tp-ret;
			else gcd = __gcd(gcd,tp-ret);
		}
	}
	for (i = gcd ; i >= 1 ; i++)
	{
		if (gcd%i == 0 && tp-i*(n-1) >= 0)
		{
			cout << "! " << tp-i*(n-1) << " " << i << "\n";
			return 0;
		}
	}
	return 0;
}