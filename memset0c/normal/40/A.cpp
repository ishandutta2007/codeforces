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

bool flag;
double a, b, dist;

int main() {
	cin >> a >> b;
	dist = sqrt(a * a + b * b);
	if (floor(dist) == dist) flag = 1;
	else {
		flag = !(int(floor(dist)) % 2);
		if (a * b < 0) flag ^= 1;
	}
	if (flag) cout << "black\n";
	else cout << "white\n";
	return 0;
}