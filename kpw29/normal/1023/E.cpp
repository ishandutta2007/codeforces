#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for (int i=(a); i<=(b); ++i)
#define boost ios_base::sync_with_stdio(false);
typedef pair <int, int> PII;
typedef long long ll;
typedef unsigned int ui;
const int mod = 1e9+7;

bool ask(int a, int b, int c, int d)
{
	cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
	string odp;
	cin >> odp;
	if (odp == "YES") return 1;
	if (odp == "NO") return 0;
	exit(0);
}
inline int dist(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}
int n;
int main()
{
	boost;
	cin >> n;
	int a = 1, b = 1;
	string odp = "";
	while (1)
	{
		if (dist(a, b, n, n) <= n - 1) break;
		if (a <= n && ask(a + 1, b, n, n)) odp += "D", ++a;
		else odp += "R", ++b;
	}
	
	string sec = "";
	int c = n, d = n;
	while (1)
	{
		if (c == a && d == b) break;
		if (d > 0 && ask(1, 1, c, d - 1)) sec += "R", --d;
		else sec += "D", --c;
	}
	
	assert(c == a && d == b);
	reverse(sec.begin(), sec.end());
	odp += sec;
	cout << "! " << odp;
}