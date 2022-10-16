#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, x = 0, t;
    string ans = "YES", type;
    cin >> N;
    ff(i, 1, N) {
        cin >> t >> type;
        if (type[0] == 'N') {
            if (x < t) ans = "NO";
            x -= t;
        }
        else if (type[0] == 'S') {
            if (x + t > 20000) ans = "NO";
            x += t;
        }
        else {
            if (x == 0 || x == 20000) ans = "NO";
        }
    }
    if (x != 0) ans = "NO";
    cout << ans << endl;
    return 0;
}