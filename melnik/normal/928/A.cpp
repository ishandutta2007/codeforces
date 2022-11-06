#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1050;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

string a[maxn];

bool kek(char x) {
	if (x == '1')
		return true;
	if (x == 'i')
		return true;
	if (x == 'l')
		return true;
	return false;
}

bool Equal(string x, string y) {
	if (x.size() != y.size())
		return false;
	for (int i = 0; i < x.size(); ++i)
		x[i] = tolower(x[i]), y[i] = tolower(y[i]);
	for (int i = 0; i < x.size(); ++i) {
		if (x[i] == y[i])
			continue;
		if (x[i] == '0' && y[i] == 'o')
			continue;
		if (x[i] == 'o' && y[i] == '0')
			continue;

		int cnt = kek(x[i]) + kek(y[i]);
		if (cnt == 2)
			continue;
		return false;
	}
	return true;
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    string x;
    cin >> x;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    	cin >> a[i];
    for (int i = 0; i < n; ++i)
    	if (Equal(x, a[i])) {
    		cout << "No" << endl;
    		return 0;
    	}
    cout << "Yes" << endl;
    return 0;
}