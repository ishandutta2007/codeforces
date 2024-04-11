#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


int n, m, K;
vector <string> a, b;

int main() {
	read(n); read(m); 
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a.push_back(s);
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		b.push_back(s);
	}
	read(K);
	int l = a.size() * b.size() / __gcd(a.size(), b.size());
	for (int i = 1; i <= K; i++) {
		int x; read(x);
		x --;
		x %= l;
		for (int j = 0, k = 0; ; j = (j + 1) % a.size(), k = (k + 1) % b.size()) {
				if (x-- == 0) {
					cout << a[j] << b[k] << endl;
					break;
				}
		}
	}
}