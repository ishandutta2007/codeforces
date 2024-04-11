#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
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
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const LL mod = 1e9+7;

LL n , m , f0 , a[2][2] , c[2][2];

void qp(LL x)
{
	if (x == 0) return;
	qp(x/2);
	LL b[2][2];
	b[0][0] = a[0][0];
	b[0][1] = a[0][1];
	b[1][0] = a[1][0];
	b[1][1] = a[1][1];
	for (int i = 0 ; i <= 1 ; i++)
	{
		for (int j = 0 ; j <= 1 ; j++)
		{
			a[i][j] = 0;
			for (int k = 0 ; k <= 1 ; k++)
			{
				a[i][j] = (a[i][j]+b[i][k]*b[k][j]+mod*mod)%mod; 
			}
		}
	}
	if (x%2)
	{
		b[0][0] = a[0][0];
		b[0][1] = a[0][1];
		b[1][0] = a[1][0];
		b[1][1] = a[1][1];
		for (int i = 0 ; i <= 1 ; i++)
		{
			for (int j = 0 ; j <= 1 ; j++)
			{
				a[i][j] = 0;
				for (int k = 0 ; k <= 1 ; k++)
				{
					a[i][j] = (a[i][j]+b[i][k]*c[k][j]+mod*mod)%mod; 
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	if (!n)
	{
		cout << "0\n";
		return 0;
	}
	n %= mod;
	f0 = n*2%mod;
	c[0][0] = 2;
	c[0][1] = 0;
	c[1][0] = -1;
	c[1][1] = 1;
	a[0][0] = 1;
	a[0][1] = 0;
	a[1][0] = 0;
	a[1][1] = 1;
	qp(m);
	f0 = (f0*a[0][0]+a[1][0]+mod*mod)%mod;
	cout << f0 << "\n";
	return 0;
}