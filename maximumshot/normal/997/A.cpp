#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, x, y;

    cin >> n >> x >> y;

    string s;

    cin >> s;

    vec< int > a;

    for(int i = 0;i < n;i++) {
        int j = i;
        while(j < n && s[i] == s[j]) j++;
        j--;
        a.push_back(s[i] - '0');
        i = j;
    }

    if((int)a.size() == 1) {
        if(a.front()) {
            cout << "0\n";
        }else {
            cout << y << "\n";
        }
        return 0;
    }

    int sz = (int)a.size();

    ll res = 1ll * ((sz - 2) / 2) * min(x, y);

    sz -= ((sz - 2) / 2) * 2;

    if(sz == 3) {
        if(a.front()) {
            res += y;
        }else {
            res += y + min(x, y);
        }
    }else { // sz == 2
        res += y;
    }

    cout << res << "\n";

    return 0;
}