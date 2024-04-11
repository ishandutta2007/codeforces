#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define cnt(x) __builtin_popcount(x)
typedef long long i64;
using namespace std;
const int N = 2000 + 10;
int n, k;
int num[N];
string digit[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int dig[10];
int rev[1 << 7];
bitset<N> dp[N];
int main() {
	for(int i = 0; i < 10; i++) {
		int mask = 0;
		for(int j = 0; j < 7; j++) mask = mask << 1 | (digit[i][j] - '0');
		rev[mask] = i;
		dig[i] = mask;
	}
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < 7; j++) {
			num[i] = num[i] << 1 | (s[j] - '0');
		}
	}
	dp[n][0] = 1;
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j < 10; j++) {
			if((dig[j] & num[i]) == num[i]) {
				int c = cnt(dig[j] ^ num[i]);
				dp[i] |= dp[i + 1] << c;
			}
		}
	}
	if(!dp[0][k]) return cout << -1 << endl, 0;
	for(int i = 0; i < n; i++) {
		for(int j = 9; j >= 0; j--) {
			if((dig[j] & num[i]) == num[i]) {
				int c = cnt(dig[j] ^ num[i]);
				if(k >= c && dp[i + 1][k - c]) {
					k -= c;
					cout << j;
					break;
				}
			}
		}
	}
	cout << endl;
	return 0;
}