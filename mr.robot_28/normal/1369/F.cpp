#include<bits/stdc++.h>
using namespace std;
#define int long long
bool win(int x, int y)
{
	if(x == y)
	{
		return 0;
	}
	if(x == y - 1)
	{
		return 1;
	}
	if(y & 1)
	{
		if(x & 1)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if(x <= y / 4)
	{
		return win(x, y / 4);
	}
	if(x > (y / 4) * 2)
	{
		return ((y - x) & 1);
	}
	return 1;
}
bool lose(int x, int y)
{
	if(x * 2 > y)
	{
		return 1;
	}
	int w = y / 2 + 3;
	while(w * 2 > y)
	{
		w--;
	}
	return win(x, w);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> can1(n), can2(n);
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		can1[i] = win(x, y);
		can2[i] = lose(x, y);
	}
	int f = 1, s = 0;
	for(int i = 0; i < n; i++)
	{
		if(f ^ s == 0)
		{
			break;
		}
		if(s == 1)
		{
			can1[i] ^= 1;
			can2[i] ^= 1;
		}
		f = can2[i];
		s = can1[i];
	}
	cout << s << " " << f;
	return 0;
}