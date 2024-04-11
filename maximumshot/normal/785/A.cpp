#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);

    int n;

    cin >> n;

    int res = 0;

    string s;

    for(int i = 0;i < n;i++) {
        cin >> s;
        if(s == "Tetrahedron") {
            res += 4;
        }else if(s == "Cube") {
            res += 6;
        }else if(s == "Octahedron") {
            res += 8;
        }else if(s == "Dodecahedron") {
            res += 12;
        }else {
            res += 20;
        }
    }

    cout << res << "\n";

    return 0;
}