#include <iostream>
#include <string>

using namespace std;

int n, k;
string s;
int a[26];

int main() {
	cin >> n >> k >> s;
	for(int i = 0; i < n; i++) {
		a[s[i] - 'A']++;
	}
	int m = n;
	for(int i = 0; i < k; i++) {
		m = min(m, a[i]);
	}
	cout << m * k << endl;
}