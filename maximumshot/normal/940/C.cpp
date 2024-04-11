#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

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

    int n, k;
    string s;

    cin >> n >> k >> s;

    vec< char > used(26);

    char mn = 'z';
    char mx = 'a';
    for(char c : s) {
        mn = min(mn, c);
        mx = max(mx, c);
        used[c - 'a'] = 1;
    }

    if(n < k) {
        cout << s + string(k - n, mn) << "\n";
        return 0;
    }

    for(int i = k - 1;i >= 0;i--) {
        if(s[i] != mx) {
            for(char c = s[i] + 1;c <= 'z';c++) {
                if(used[c - 'a']) {
                    cout << s.substr(0, i) + string(1, c) + string(k - i - 1, mn) << "\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}