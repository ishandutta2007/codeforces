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

const int maxn = 1000100;
int tab[maxn], n, m;

int main()
{
	boost;
	int x, d;
	cin >> x >> d;
	string a, b;
	cin >> a >> b;
	while (a.size() && b.size() && a[a.size() - 1] == b[b.size() - 1]) a.pop_back(), b.pop_back();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (a.size() && b.size() && a[a.size() - 1] == b[b.size() - 1]) a.pop_back(), b.pop_back();
	if (b.size() == 0)
	{
		if (a.size() == 0) cout << "YES";
		else if (a.size() == 1 && a[0] == '*') cout << "YES";
		else cout << "NO";
		exit(0);
	}
	if (a.size() == 0) cout << "NO";
	else if (a.size() == 1 && a[0] == '*') cout << "YES";
	else cout << "NO";
}