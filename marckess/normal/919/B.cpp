#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

vi nm;

bool esPer (int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res == 10;
}

void precal () {
    int x = 0;
    while (nm.size() < 10000) {
        if (esPer(x))
            nm.push_back(x);
        x++;
    }
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
    precal();

    int k;
    cin >> k;

    cout << nm[k-1] << endl;

	return 0;
}