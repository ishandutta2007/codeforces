#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, x;
ll ans;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	int T = read();
	while(T --)
	{
		cin >> x;
		ans += x - 1;
		int Ans = (!(ans & 1) + 1);
		cout << Ans << endl;
	}
	return 0;
}