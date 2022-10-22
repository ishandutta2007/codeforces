#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, a, b;

    cin >> n >> a >> b;

    string s;
    cin >> s;

    a--, b--;

    if(s[a] == s[b]) {
        cout << 0 << "\n";
    }else {
        cout << 1 << "\n";
    }

    return 0;
}