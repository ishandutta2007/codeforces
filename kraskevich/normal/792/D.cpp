#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

ll n;
int h;

ll make_step(ll x, char d) {
    int level = 0;
    ll cur = x;
    while (cur % 2 == 0) {
        cur /= 2;
        level++;
    }
    ll del_up = 1ll << level;
    ll del_low = del_up / 2;
    if (d == 'U') {
        if (level == h)
            return x;
        if ((cur - 1) % 4 == 0)
            x += del_up;
        else
            x -= del_up;
        return x;
    }
    if (level == 0)
        return x;
    if (d == 'L')
        x -= del_low;
    else
        x += del_low;
    return x;
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    while ((1ll << h) <= n)
        h++;
    h--;
    int q;
    cin >> q;
    while (q--) {
        ll v;
        cin >> v;
        string s;
        cin >> s;
        for (char c : s)
            v = make_step(v, c);
        cout << v << "\n";
    }
}