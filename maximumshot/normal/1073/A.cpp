#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    string s;

    cin >> s;

    for(int i = 0;i + 1 < n;i++) {
        if(s[i] != s[i + 1]) {
            cout << "YES\n";
            cout << s[i] << s[i + 1];
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}