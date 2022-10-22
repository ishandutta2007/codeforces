#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

long long n, l, a[500000];
string s;
bool used[500000];

int main() {
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	s = '0' + s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	l = 1;
	while (true) {
		if (s[l] == '<')
			l -= a[l];
		else
			l += a[l];
		if (l < 1 || l > n) {
			cout << "FINITE";
			return 0;
		}
		if (used[l]) {
			cout << "INFINITE";
			return 0;
		}
		used[l] = true;
	}
	return 0;
}