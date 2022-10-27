

#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector <vector <int> > x, y;
vector <vector <char> > mat;
bool connect(int p, int q, int r, int s, char d1, char d2)
{
	if(x[r][s] == -1)
	{
		mat[p][q] = d1;
		if(mat[r][s] == '\0')
		{
			mat[r][s] = d2;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}
void dfs(int p, int q, char d)
{
	if(mat[p][q] != '\0')
	{
		return;
	}
	mat[p][q] = d;
	if(x[p][q] == x[p + 1][q] && y[p][q] == y[p + 1][q])
	{
		dfs(p + 1, q, 'U');
	}
	if(x[p][q] == x[p][q + 1] && y[p][q + 1] == y[p][q])
	{
		dfs(p, q + 1, 'L');
	}
	if(x[p][q] == x[p][q - 1] && y[p][q] == y[p][q - 1])
	{
		dfs(p, q - 1, 'R');
	}
	if(x[p][q] == x[p - 1][q] && y[p][q] == y[p - 1][q])
	{
		dfs(p - 1, q, 'D');
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	mat.resize((1 << 10) + 5, vector <char> ((1 << 10) + 5));
	x.resize((1 << 10) + 5, vector <int> ((1 << 10) + 5));
	y.resize((1 << 10) + 5, vector <int> ((1 << 10) + 5));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++){
			cin >> x[i][j] >> y[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
		{
			if(x[i][j] == -1)
			{
				bool res = (mat[i][j] != '\0');
				if(res == 0) res = connect(i, j , i + 1, j, 'D', 'U');
				if(res == 0) res = connect(i, j, i, j + 1, 'R', 'L');
				if(res == 0) res = connect(i, j, i - 1, j, 'U', 'D');
				if(res == 0) res = connect(i, j, i, j - 1, 'L', 'R');
				if(res == 0)
				{
					cout << "INVALID";
					return 0;
				}
			}
			else if(x[i][j] == i && y[i][j] == j)
			{
				dfs(i, j, 'X');
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++){
			if(mat[i][j] == '\0')
			{
				cout << "INVALID";
				return 0;
			}
		}
	}
	cout << "VALID\n";
	for(int i =1 ; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cout << mat[i][j];
		}
		cout << "\n";
	}
	return 0;
}