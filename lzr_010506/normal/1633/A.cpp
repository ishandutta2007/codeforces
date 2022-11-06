#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define X first
#define Y second
#define pii pair<int, int>
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T --)
	{
		int n;
		cin >> n;
		if(n % 7 == 0) {cout << n << "\n"; continue;}
		n = n / 10 * 10;
		rep0(i, 10)
		{
			int nw = n + i;
			if(nw % 7 == 0) {cout << nw << "\n"; break;}
		}
	}
}