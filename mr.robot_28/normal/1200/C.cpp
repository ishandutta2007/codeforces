#include<bits/stdc++.h>
using namespace std;
#define int long long
int nod(int a, int b)
{
	if(a == 0 || b == 0)
	{
		return a + b;
	}
	else if(a > b)
	{
		return nod(a % b, b);
	}
	else
	{
		return nod(a, b % a);
	}
}
signed main()
{
	int n, m, q;
	cin >> n >> m >> q;
	int k = nod(n, m);
	int k1 = n / k;
	int k2 = m / k;
	for(int i = 0; i < q; i++)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		int ind1 = 0, ind2 = 0;
		if(sx == 1)
		{
			ind1 = (sy - 1) / k1;
			ind1++;
		}
		else
		{
			ind1 = (sy - 1) / k2;
			ind1++;
		}
		if(ex == 1)
		{
			ind2 = (ey - 1) / k1;
			ind2++; 
		}
		else
		{
			ind2 = (ey - 1) / k2;
			ind2++;
		}
		if(ind1 == ind2)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}