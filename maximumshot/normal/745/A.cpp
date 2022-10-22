#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    string s;
    cin >> s;

    set< string > q;

    for(int i = 0;i < (int)s.size();i++) {
        q.insert( s.substr(i) + s.substr(0, i) );
    }

    cout << (int)q.size() << "\n";

    return 0;
}