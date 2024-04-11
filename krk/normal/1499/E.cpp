#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int Maxn = 1005;
const int Maxl = 26;

string A;
string B;
int dp[Maxn][Maxn][Maxl];
int res;

int main()
{
	cin >> A;
	cin >> B;
	int lst = Maxl, cnt = 0;
	for (int i = 0; i < A.length(); i++) {
		if (lst == A[i] - 'a') cnt = 0;
		lst = A[i] - 'a'; cnt++;
		for (int j = 0; j < B.length(); j++)
			if (lst != B[j] - 'a')
				dp[i + 1][j + 1][B[j] - 'a'] = (dp[i + 1][j + 1][B[j] - 'a'] + cnt) % mod;
	}
	lst = Maxl, cnt = 0;
	for (int j = 0; j < B.length(); j++) {
		if (lst == B[j] - 'a') cnt = 0;
		lst = B[j] - 'a'; cnt++;
		for (int i = 0; i < A.length(); i++)
			if (lst != A[i] - 'a')
				dp[i + 1][j + 1][A[i] - 'a'] = (dp[i + 1][j + 1][A[i] - 'a'] + cnt) % mod;
	}
	for (int i = 0; i <= A.length(); i++)
		for (int j = 0; j <= B.length(); j++)
			for (int l = 0; l < Maxl; l++) if (dp[i][j][l]) {
				res = (res + dp[i][j][l]) % mod;
				if (i < A.length() && A[i] - 'a' != l)
					dp[i + 1][j][A[i] - 'a'] = (dp[i + 1][j][A[i] - 'a'] + dp[i][j][l]) % mod;
				if (j < B.length() && B[j] - 'a' != l)
					dp[i][j + 1][B[j] - 'a'] = (dp[i][j + 1][B[j] - 'a'] + dp[i][j][l]) % mod;
			}
	printf("%d\n", res);
    return 0;
}