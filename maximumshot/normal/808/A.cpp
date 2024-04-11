#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    string s;

    cin >> s;

    int x = 0;
    for(char c : s) x = x * 10 + c - '0';

    if(x < 10) {
        cout << "1\n";
        return 0;
    }

    if(s[0] != '9') {
        ll y = s[0] - '0' + 1;
        for(int i = 1;i < (int)s.size();i++) y *= 10;
        cout << y - x << "\n";
    }else {
        ll y = 1;
        for(int i = 0;i < (int)s.size();i++) {
            y *= 10;
        }
        cout << y - x << "\n";
    }

    return 0;
}