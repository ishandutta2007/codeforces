#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 53;

string suit = "SDHC";
string value = "23456789TJQKA";

int n;
int car[Maxn];
int dp[Maxn][Maxn][Maxn][Maxn];

int getId(const string &c) { return suit.find(c[1]) * value.length() + value.find(c[0]); }

bool Ok(int a, int b) { return a / value.length() == b / value.length() || a % value.length() == b % value.length(); }

bool Get(int lst, int a, int b, int c)
{
	if (!dp[lst][a][b][c])
		if (lst == 0) dp[lst][a][b][c] = 1;
		else {
			dp[lst][a][b][c] = -1;
			if (lst - 3 >= 0 && Ok(car[lst - 3], c) && Get(lst - 1, c, a, b) ||
				Ok(b, c) && Get(lst - 1, (lst - 3 >= 0? car[lst - 3]: 0), a, c))
				dp[lst][a][b][c] = 1;
		}
	return dp[lst][a][b][c] == 1;
}

int main()
{
	scanf("%d", &n);
	string c;
	for (int i = 0; i < n; i++) {
		cin >> c; car[i] = getId(c);
	}
	if (Get(n - 1, (n - 3 >= 0? car[n - 3]: 0), (n - 2 >= 0? car[n - 2]: 0), car[n - 1]))
		printf("YES\n");
	else printf("NO\n");
	return 0;
}