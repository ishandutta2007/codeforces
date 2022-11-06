#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int n;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main() 
{
	n = read();
	int Ans1 = INF, Ans2 = -INF;
	bool can = 1;

	while(n --)
	{
		int c = read();
		int d = read();
		if (d == 1 && Ans1 < 1900) can = 0;
		else if (d == 2 && Ans2 >= 1900) can = 0;
		if (Ans1 < Ans2) can = 0;

		if (d == 1) 
		{
			Ans2 = max(Ans2 + c, 1900 + c);
			if (Ans1 != INF) Ans1 += c;
		}
		if (d == 2) 
		{
			Ans1 = min(Ans1 + c, 1899 + c);
			if (Ans2 != -INF) Ans2 += c;
		}

		if (Ans1 > INF) Ans1 = INF;
		if (Ans2 < -INF) Ans2 = -INF;
	}
	if (Ans1 < Ans2) can = 0;
	if (!can) {cout << "Impossible" << endl;return 0;}
	if (Ans1 == INF) cout << "Infinity" << endl;
	else cout << Ans1 << endl;
	return 0;
}