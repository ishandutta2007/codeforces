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
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int mod = 1e9 +7;
int n;
int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		cin >> n;
		if(n < 3) cout << -1;
		else if(n % 4 == 0) cout << n / 4;
		else if(n % 4 == 2) cout << n / 4;
		else if(n % 4 == 1) 
		{
			if(n == 5) cout << -1;
			else cout << n / 4 - 1;
		}
		else
		{
			if(n == 7 || n == 11) cout << -1;
			else cout << n / 4 - 1;
		}
		puts("");
	}
	
	return 0;
}

//sigma x sigma k C(n-x-(x-2k),n/2-x+k)*(n/2-x+k)!^2