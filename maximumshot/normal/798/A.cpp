#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    string s;

    cin >> s;

    for(int i = 0;i < (int)s.size();i++) {
        for(char x = 'a';x <= 'z';x++) {
            if(x == s[i]) continue;
            string t = s;
            t[i] = x;
            string rt = t;
            reverse(ALL(rt));
            if(t == rt) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

    return 0;
}