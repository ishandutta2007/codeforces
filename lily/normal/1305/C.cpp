#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


#define N 201111

int n, m;
int a[N];
set <int> s;
vector <int> b;

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (s.count(a[i] % m)) {
			puts("0");
			return 0;
		}
		s.insert(a[i] % m);
		b.push_back(a[i]);
	}
	LL ans = 1;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			ans = ans * abs(b[i] - b[j]) % m;
		}
	cout << (ans % m + m) % m << endl;


}