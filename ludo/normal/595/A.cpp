#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream &out, const pii &a) { return out << '(' << a.first << ", " << a.second << ')'; }
istream& operator>>(istream &in, pii &a) { return in >> a.first >> a.second; }

int main()
{
#ifdef LOCAL
//    assert(freopen("input.txt", "r", stdin));
#else
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#endif // LOCAL

	int n, m, a = 0;
	cin >> n >> m;
	while (n--) {
		int x, y;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			if (x || y) a++;
		}
	}
	cout << a << endl;
    return 0;
}