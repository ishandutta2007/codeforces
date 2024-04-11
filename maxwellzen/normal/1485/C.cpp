#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t;
ll x, y, ans, start, pre, toadd, temp;
//10438801384
void solve() {
    cin >> x >> y;
    ans = 0;
    start = 1;
    pre = 1;

    ll start = min(y, (ll)sqrt(x-1));
    ans = (start * (start-1) / 2);
    pre = y+1;
//    for (ll i = 1; i <= start+2; i++) {
//        temp = pre;
//        for (ll z = temp-1; z > 0; z /= 2) {
//            while (x / (temp - z + 1) >= i-1) temp -= z;
//        }
//        temp = max(start+1, temp);
//        ll toadd = (i-1) * (pre - temp);
//        ans += toadd;
//        pre = temp;
//        if (temp == start+1) break;
//    }
    for (ll i = start+1; i <= y && i < x;) {
        ll toadd = x / (i+1);
        if (toadd==0) break;
        ll temmie = i;
        for (ll dd = x - toadd; dd > 0; dd  /= 2) {
            while (x / (temmie + dd + 1)==toadd) temmie += dd;
        }
        temmie = min(y, temmie);
        toadd *= (temmie + 1 - i);
        i = temmie + 1;
        ans += toadd;
    }
//    ll d = 0;
//    while(true) {
//        d++;
//        ll guess = pre;
//        for (int z = x; z > 0; z /= 2) {
//            while ((guess+1) * (guess-d) <= x) guess += z;
//        }
//        start = min(y, guess);
//        cout << d << '\t' << pre << '\t' << start << '\n';
//        toadd = (start - d) * (start - d + 1) / 2 - (pre - d) * (pre - d + 1) / 2;
////        toadd = ((start - pre) * (start - pre + 1) / 2) + (start - pre) * (pre - d);
//        if (toadd<=0) break;
//        ans += toadd;
//        pre = start;
//    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}