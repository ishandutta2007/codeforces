#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pii pair<int, int>
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ALL(x) (x).begin(), (x).end()
using namespace std;
int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 3e5 + 10;
const int inf = 1e9 + 17;
int n, m;
map<string, int> s;
string a, b;
int main()
{
	n = read();
	rep(i, 1, n)
	{
		a.clear();
		b.clear();
		cin >> a;
		int len = a.size();
		reverse(a.begin(), a.end());
		rep(j, 0, len - 1)
		{
			if(a[j] == 'h' && j + 1 < len)
			{
				while(a[j + 1] == 'k') j ++;
				b.pb('h');
			}
			else if(a[j] == 'u') b.pb('o'), b.pb('o');
			else b.pb(a[j]);
		}
		s[b] ++;
	}
	cout << s.size();
	return 0;
}