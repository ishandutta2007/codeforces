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
		string a;
		cin >> a;
		int n = a.size();
		int z = 0, o = 0;
		rep0(i, n)
			if(a[i] == '0') z ++;
			else o ++;
		if(z != o) cout << min(z, o) << "\n";
		else cout << z - 1 << "\n";
	}
}