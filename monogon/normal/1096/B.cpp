#include <iostream>

#define M 998244353

using namespace std;

int n;
string s;

int main() {
	cin >> n >> s;
	char a = s[0];
	char b = s[n - 1];
	long long x = 0;
	long long y = 0;
	for(; x < n && s[x] == a; x++);
	for(; y < n && s[n - y - 1] == b; y++);
	cout << (a == b ? ((x + 1) * (y + 1)) % M : (x + y + 1) % M);
}