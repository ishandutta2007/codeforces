#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    int mx = 0;

    string s;

    while(cin >> s) {
        int cnt = 0;
        for(char c : s) {
            if(c >= 'A' && c <= 'Z') {
                cnt++;
            }
        }
        mx = max(mx, cnt);
    }

    cout << mx << "\n";

    return 0;
}