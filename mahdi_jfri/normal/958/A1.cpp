#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e2 + 20;

int n;

string s[maxn] , t[maxn] , x[maxn];

bool is()
{
	for(int i = 0; i < n; i++)
		if(s[i] != t[i])
			return 0;
	return 1;
}

void rotate()
{
	for(int i = 0; i < n; i++)
	{
		x[i] = "";

		for(int j = 0; j < n; j++)
			x[i] += s[j][n - i - 1];
	}

	for(int i = 0; i < n; i++)
		s[i] = x[i];
}

bool solve()
{
	for(int i = 0; i < 2; i++)
	{
		for(int i = 0; i < n; i++)
			reverse(s[i].begin() , s[i].end());

		for(int j = 0; j < 4; j++)
		{
			if(is())
				return 1;
			rotate();
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < n; i++)
		cin >> t[i];

	bool f = 0;

	f |= solve();

	for(int i = 0; i < n - i - 1; i++)
		swap(s[i] , s[n - i - 1]);

	f |= solve();

	cout << (f? "Yes" : "No") << endl;
}