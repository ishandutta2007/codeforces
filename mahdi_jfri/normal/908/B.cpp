#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e2 + 20;

string s[maxn];

int x1[10];

int x , y;

int main()
{
	for(int i = 0; i < 4; i++)
		x1[i] = i;
	int n , m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		for(int j = 0; j < m; j++)
			if(s[i][j] == 'S')
			{
				x = i;
				y = j;
			}
	}

	string ins;
	cin >> ins;
	
	int res = 0;
	do
	{
		int tmpx = x , tmpy = y;
		bool f = 1;
		for(int i = 0; i < (int)ins.size(); i++)
		{
			int z = x1[ins[i] - '0'];
			if(z == 0)
				x--;
			if(z == 1)
				x++;
			if(z == 2)
				y++;
			if(z == 3)
				y--;
			if(x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#')
				f = 0;
			else if(s[x][y] == 'E')
				break;
		}
		if(f && s[x][y] == 'E')
			res++;
		x = tmpx;
		y = tmpy;
	}while(next_permutation(x1 , x1 + 4));
	cout << res << endl;
}