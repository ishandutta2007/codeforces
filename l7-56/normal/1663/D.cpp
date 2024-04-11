#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

string s;
int x;

int main() {
	cin >> s >> x;
	if (s == "ABC") return printf(x <= 1999 ? "YES\n" : "NO\n"), 0;
	if (s == "ARC") return printf(x <= 2799 ? "YES\n" : "NO\n"), 0;
	if (s == "AGC") return printf(x >= 1200 ? "YES\n" : "NO\n"), 0;
	return 0;
}