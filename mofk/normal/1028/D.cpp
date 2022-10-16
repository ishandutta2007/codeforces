#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n;
int type[500005], val[500005];
set <int> s;
int buy, sell;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string in;
        cin >> in >> val[i];
        if (in == "ADD") type[i] = 1;
        else type[i] = -1;
    }
    s.insert(-1);
    s.insert((int)1e9);
    buy = -1; sell = 1e9;
    int ans = 1, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (type[i] == -1) {
            if (val[i] < buy || val[i] > sell) return cout << 0 << endl, 0;
            int mark = 0;
            if (val[i] == buy || val[i] == sell) mark = 1;
            auto isell = s.upper_bound(val[i]);
            sell = *isell;
            auto ibuy = s.lower_bound(val[i]); --ibuy;
            buy = *ibuy;
            s.erase(val[i]);
            cnt = 0;
            if (mark) continue;
            ans = ans * 2 % mod;
        }
        else {
            if (buy < val[i] && val[i] < sell) ++cnt;
            s.insert(val[i]);
        }
    }
    ans = 1ll * ans * (cnt + 1) % mod;
    cout << ans << endl;
    return 0;
}