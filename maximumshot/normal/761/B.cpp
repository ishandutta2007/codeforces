#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, L;
    cin >> n >> L;

    vec< int > a(n);
    vec< int > b(n);

    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    for(int i = 0;i < n;i++) {
        cin >> b[i];
    }

    for(int x = 0;x < L;x++) {
        for(int y = 0;y < L;y++) {
            vec< int > p1, p2;
            for(int i = 0;i < n;i++) {
                p1.push_back( (x + a[i]) % L );
                p2.push_back( (y + b[i]) % L );
            }
            int ok = 0;
            for(int i = 0;i < n;i++) {
                int tmp = 1;
                for(int it = 0;it < n;it++) {
                    if( p1[(i + it) % n] != p2[it] ) {
                        tmp = 0;
                        break;
                    }
                }
                if(tmp) {
                    ok = 1;
                    break;
                }
            }
            if(ok) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

    return 0;
}