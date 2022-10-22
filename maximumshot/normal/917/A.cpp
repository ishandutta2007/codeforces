#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef unsigned int ui;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

vec< vec< char > > get(string s) {
    int n = (int)s.size();
    vec< vec< char > > res(n, vec< char >(n));
    for(int l = 0;l < n;l++) {
        int d = 0;
        int c = 0;
        for(int r = l;r < n;r++) {
            if(s[r] == '(') {
                d++;
            }else if(s[r] == ')') {
                if(d > 0) {
                    d--;
                }else {
                    if(c > 0) {
                        c--;
                    }else {
                        break;
                    }
                }
            }else {
                c++;
            }
            if(d <= c && !((c - d) & 1)) {
                res[l][r] = 1;
            }
        }
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    string s;

    cin >> s;

    int n = (int)s.size();

    vec< vec< char > > a = get(s);

    reverse(ALL(s));

    for(char& c : s) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    vec< vec< char > > b = get(s);

    int res = 0;

    reverse(ALL(s));

    for(char& c : s) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    for(int l = 0;l < n;l++) {
        for(int r = l;r < n;r++) {
            if(a[l][r] && b[n - r - 1][n - l - 1]) {
                res++;
//                cout << s.substr(l, r - l + 1) << "\n";
            }
        }
    }

    cout << res << "\n";

    return 0;
}