// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

int n;
string s;
map < string, int > mp;

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		cin >> s;
		if (mp[s]) {
			cout << s << mp[s] << endl;
		} else {
			puts("OK");
		}
		mp[s]++;
	}
	return 0;
}