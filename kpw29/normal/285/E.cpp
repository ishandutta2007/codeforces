#include <iostream>
#include <algorithm>
using namespace std;
const int BASE = int(1e9) + 7;

long long f[1010][1010][4], F[1010], c[1010][1010];

void addMod(long long &x, long long y)
{
	x += y; 
	if (x >= BASE) x -= BASE;
}

int main()
{
	int n, el;
	cin >> n >> el;
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i; j++)
			c[i][j] = j ? (c[i - 1][j] + c[i - 1][j - 1]) % BASE : 1;
	
	f[0][0][2] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++)
			for (int z = 0; z < 4; z++)
			{
				if (z & 1) addMod(f[i][j + 1][z / 2 + 2], f[i - 1][j][z]);
				if (i < n) addMod(f[i][j + 1][z / 2], f[i - 1][j][z]);
				addMod(f[i][j][z / 2 + 2], f[i - 1][j][z]);
			}
			
	for (int j = 0; j <= n; j++)
	{
		for (int z = 0; z < 4; z++) addMod(F[j], f[n][j][z]);
		for (int k = 2; k <= n - j; k++) F[j] = F[j] * k % BASE;
	}
			
	for (int i = n - 1; i >= 0; i--)
		for (int j = i + 1; j <= n; j++)
			addMod(F[i], BASE - F[j] * c[j][i] % BASE);
			
	cout << F[el] << endl;
}