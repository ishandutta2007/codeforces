#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;
    cin >> n;

    string s;

    cin >> s;

    deque< char > t;

    for(int i = 0;i < n;i++) {
        if((n - i) % 2) t.push_back( s[i] );
        else t.push_front( s[i] );
    }

    for(auto i : t) cout << i;
    cout << "\n";

    return 0;
}