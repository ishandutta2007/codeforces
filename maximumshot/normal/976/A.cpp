#include <bits/stdc++.h>

using namespace std;

#define ALL(x) begin(x), end(x)
#define vec vector

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    string s;

    cin >> s;

    if(s == "0") {
        cout << "0\n";
        return 0;
    }

    cout << "1" + string(count(ALL(s), '0'), '0') << "\n";

    return 0;
}