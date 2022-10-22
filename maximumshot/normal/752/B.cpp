#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    string s, t;

    cin >> s >> t;

    vec< int > a(26, -1);

    for(int i = 0;i < (int)s.size();i++) {
        int x = s[i] - 'a';
        int y = t[i] - 'a';
        if( a[x] != -1 && a[x] != y ) {
            cout << "-1\n";
            return 0;
        }
        if( a[y] != -1 && a[y] != x ) {
            cout << "-1\n";
            return 0;
        }
        a[x] = y;
        a[y] = x;
    }

    vec< pair< char, char > > res;

    vec< char > used(26, 0);

    for(int i = 0;i < 26;i++) {
        if(a[i] != -1 && a[i] != i && !used[i]) {
            used[i] = used[ a[i] ] = 1;
            res.push_back( make_pair( char(i + 'a'), char(a[i] + 'a') ) );
        }
    }

    cout << (int)res.size() << "\n";

    for(auto i : res) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}