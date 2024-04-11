#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll c, h1, h2, w1, w2;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }

    cin >> c >> h1 >> h2 >> w1 >> w2;
    if (h1*w2 < h2*w1) {
        swap(h1, h2);
        swap(w1, w2);
    }

    if (w1 > 10000) {
        ll ans = 0;
        for (int i=0; w1*i <= c; i++)
            ans = max(ans, h1*i + h2*((c-w1*i)/w2));
        cout << ans;
    } else {
        ll ans = 0;
        for (int i=0; w2*i <= c && i < 100000; i++)
            ans = max(ans, h2*i + h1*((c-w2*i)/w1));
        cout << ans;
    }
}