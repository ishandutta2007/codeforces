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

    int n;
    cin >> n;

    vec< int > a[2];

    for(int x, i = 0;i < n;i++) {
        cin >> x;
        if((x % 2 + 2) % 2) {
            a[1].push_back(x);
        }else {
            a[0].push_back(x);
        }
    }

    sort(ALL(a[0]));
    sort(ALL(a[1]));

    int ans = 0;

    for(int x : a[0]) {
        if(x >= 0) ans += x;
    }

    ans += a[1].back();
    a[1].pop_back();

    while((int)a[1].size() > 1) {
        int sz = (int)a[1].size();
        int x = a[1][sz - 1] + a[1][sz - 2];
        if(x >= 0) {
            ans += x;
            a[1].pop_back();
            a[1].pop_back();
        }else {
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}