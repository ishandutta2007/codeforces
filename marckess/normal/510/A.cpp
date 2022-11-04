#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, m;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++)
                cout << '#';
        } else {
            if (i % 4 == 3)
                cout << '#';
            for (int j = 1; j < m; j++)
                cout << '.';
            if (i % 4 == 1)
                cout << '#';
        }
        cout << endl;
    }

    return 0;
}