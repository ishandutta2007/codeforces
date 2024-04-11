#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, p;

    cin >> n >> p;

    string s;

    cin >> s;

    vec< vec< int > > a(p);

    for(int i = 0;i < n;i++) {
        a[i % p].push_back(i);
    }

    for(int i = 0;i < p;i++) {
        int cntp = 0;
        int have0 = 0;
        int have1 = 0;
        for(int x : a[i]) {
            cntp += s[x] == '.';
            have0 |= s[x] == '0';
            have1 |= s[x] == '1';
        }
        if(cntp > 1) {
            int last = 0;
            for(int x : a[i]) {
                if(s[x] == '.') {
                    s[x] = last + '0';
                    last ^= 1;
                }
            }
            for(char c : s) {
                if(c == '.') c = '0';
                cout << c;
            }
            cout << "\n";
            return 0;
        }
        if(have0 && have1) {
            for(char c : s) {
                if(c == '.') c = '0';
                cout << c;
            }
            cout << "\n";
            return 0;
        }
        if(!have0 && !have1) continue;
        if(cntp == 0) continue;
        int need = have0 ? 1 : 0;
        for(char c : s) {
            if(c == '.') c = need + '0';
            cout << c;
        }
        cout << "\n";
        return 0;
    }

    cout << "No\n";

    return 0;
}