#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)

int n, m;

int main() {
	cin >> n >> m;
	string s, a, b;
	for (int i = 1; i <= 999; i++) a += '9'; 
	for (int i = 1; i <= 999; i++) a += '0', b += '9'; 
	a += '1'; b += '9';
	cout << a << endl <<  b << endl;
	return 0;
}