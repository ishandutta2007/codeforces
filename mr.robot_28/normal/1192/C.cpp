#include<bits/stdc++.h>
 
using namespace std;
#define int unsigned long long
const int CONST = 998244353;
const int CONST2 = CONST *1ll * CONST;
const int CONST3 = CONST * 10000000ll;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <string> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	long long ans1 = 0, ans2 = 0;
	vector <vector <vector <int> > > g(11, vector <vector <int> > (62, vector <int> (62)));
	set <string> e;
	for(int i =0; i < n; i++)
	{
		int a = 0, b= 0;
			if(A[i][0] >= 'a' && A[i][0] <= 'z')
			{
				a = A[i][0] - 'a';
			}
			else if(A[i][0] >= 'A' && A[i][0] <= 'Z')
			{
				a = A[i][0] - 'A' + 26;
			}
			else
			{
				a = A[i][0] - '0' + 52;
			}
			char t = A[i][A[i].size() - 1];
		if(t >= 'a' && t <= 'z')
		{
			b = t - 'a';
		}
		else if(t >= 'A' && t <= 'Z')
		{
			b= t - 'A' + 26;
		}
		else
		{
			b = t - '0' + 52;
		}
		if(e.find(A[i]) == e.end())
		{
			g[A[i].size()][a][b]++;
			e.insert(A[i]);
		}
		reverse(A[i].begin(), A[i].end());
		if(e.find(A[i]) == e.end())
		{
			g[A[i].size()][b][a]++;
			e.insert(A[i]);
		}
	}
	vector <vector <vector <int> > > cnt(62, vector <vector <int> > (62, vector <int> (62)));
	int j = 0;
	int a, b, c ,d;
	for(int i= 3; i <= 10; i++)
	{
		for(a = 0; a < 62; a++)
		{
			for(b = 0; b < 62; b++)
			{
				for(c = 0; c < 62; c++)
				{
					if(a > b || b > c && a != b && b != c && a != c)
					{
						int a1 = a, b1 = b, c1 = c;
						if(a1 > b1)
						{
							swap(a1, b1);
						}
						if(b1 > c1)
						{
							swap(b1, c1);
						}
						if(a1 > b1)
						{
							swap(a1, b1);
						}
						cnt[a][b][c] = cnt[a1][b1][c1];
						continue;
					}
					cnt[a][b][c] = 0;
					long long res = 0;
					for(d = 0; d < 62; d++)
					{
						res +=  (g[i][a][d] *1ll * g[i][b][d]) *1ll * g[i][c][d]; 
						if(res >= CONST3)
						{
							res -= CONST3;
						}
					}
					cnt[a][b][c] = res % CONST;
				}
			}
		}
		for(a = 0; a < 62; a++)
		{
			for(b = 0; b < 62; b++)
			{
				for(c = 0; c < 62; c++)
				{
					if(cnt[a][b][c] == 0)
					{
						continue;
					}
					for(d = 0; d < 62; d++)
					{
						if(a == b || b == c || a == d || a == c || b == d || c == d)
						{
							ans1 = ans1 + (cnt[a][b][c] * cnt[a][b][d] % CONST) * (cnt[a][c][d] * cnt[b][c][d] % CONST);
						}
						else if(a < b && b < c && c < d)
						{
							ans2 += (cnt[a][b][c] * cnt[a][c][d] % CONST) * (cnt[a][b][d] * 1ll * cnt[b][c][d] % CONST);
						}
						if(ans1 >= CONST2)
						{
							ans1 -= CONST2;
						}
						if(ans2 >= CONST2)
						{
							ans2 -= CONST2;
						}
					}
				}
			}
		}
	}
	cout << (ans1 + ans2 % CONST * 24) % CONST;
	return 0;
}