#include <bits/stdc++.h>
#define max_n 10000 + 13
#define INF 10000000 + 13

using namespace std;

const double EPS = 1E-9;

int n, m, a[20][20], d[20][20], x1, x2, k, g[20] = {0};
string names[20], s1, s2;

int findn (string s)
{
	for (int i = 0; i < n; i++)
		if (names[i] == s)
			return i;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			a[i][j] = 1;

	for (int i = 0; i < n; i ++)
		cin >> names[i];
	
	for (int i = 0; i < m; i ++)
	{
		cin >> s1 >> s2;
		x1 = findn (s1);
		x2 = findn (s2);
		a[x1][x2] = a[x2][x1] = 0; 
	}

	int nb = n * (n - 1) / 2 - m;

	int max_res = -INF, z1, z2;
	vector <int > res;
	bool team;
	int tres = 0;

	while (!g[n])
	{
		team = true;

		for (z1 = 0; z1 < n; z1 ++)
			for (z2 = 0; z2 < n; z2 ++)
				if (z1 != z2 && g[z1] && g[z2] && !a[z1][z2])
				{
					team = false;
					goto b1;						
				}
		b1:;
		if (team)
		{
			tres = 0;
			for (int i = 0; i < n; i ++)
				if (g[i]) tres ++;
			if (tres > max_res)
			{
				max_res = tres;

				res.resize (0);
				for (int i = 0; i < n; i ++)
					if (g[i]) res.push_back (i);
			}
		}	
		
		g[0]++;
		for (int i = 0; i < n; i++)
			if (g[i] > 1)
				g[i] = 0, g[i + 1]++;
	}

	cout << max_res << endl;

	vector <string > r1;

	for (int i = 0; i < res.size(); i++)
		r1.push_back (names[res[i]]);
	sort (r1.begin(), r1.end());

	for (int i = 0; i < r1.size(); i++)
		cout << r1[i] << "\n";
	return 0;
}