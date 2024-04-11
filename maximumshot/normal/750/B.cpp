#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;

    cin >> n;

    int t;
    string s;

    int y = 0;

    for(int iter = 0;iter < n;iter++) {
        cin >> t >> s;
        if(s == "North") {
            if(y + t > 0) {
                cout << "NO\n";
                return 0;
            }else {
                y += t;
            }
        }else if(s == "South") {
            if(y - t < -20000) {
                cout << "NO\n";
                return 0;
            }else {
                y -= t;
            }
        }else {
            if(y == 0 || y == -20000) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    if(y != 0) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
    }

    return 0;
}