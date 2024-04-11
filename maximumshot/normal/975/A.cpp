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

    set< string > a;

    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        sort(ALL(s));
        s.erase(unique(ALL(s)), s.end());
        a.insert(s);
    }

    cout << (int)a.size() << "\n";

    return 0;
}