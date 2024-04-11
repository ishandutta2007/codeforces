#include <bits/stdc++.h>
#define trace(x) cerr << #x <<" = " << x << endl
#define _ << " _ " <<
#define sz(a) int((a).size())
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int n;
ll l, a[N];
ll cl[N], cr[N], s[N], f[N];
int check1(ll x) {
    ll now = 0;
    for(int i = 1; i <= n; i++) {
        if(now + x > a[i + 1]) return 0;
        now = max(now + x, a[i]);
    }
    return 1;
}
int check2(ll x) {
    ll now = 0;
    for(int i = 1; i <= n; i++) {
        if(now + x < a[i]) return 0;
        now = min(now + x, a[i + 1]);
    }
    return now >= l;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> l >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = l;
    ll a = 0, b = l, pl = -1, pr = -1;
    while(a <= b) {
        ll mid = (a + b) / 2;
        if(check1(mid)) pl = mid, a = mid + 1;
        else b = mid - 1;
    }
    a = 0, b = l;
    while(a <= b) {
        ll mid = (a + b) / 2;
        if(check2(mid)) pr = mid, b = mid - 1;
        else a = mid + 1;
    }
    cl[0] = cr[0] = 0;
    for(int i = 1; i <= n; i++) {
        cl[i] = max(cl[i - 1] + pl, ::a[i]);
        cr[i] = min(cr[i - 1] + pr, ::a[i + 1]);
    }
    ll now = l;
    for(int i = n; i >= 1; i--) {
        ll up = (now - ::a[i]), down = (now - ::a[i - 1]);
        up = max(up, pl), down = min(down, pr);
        up = max(up, now - cr[i - 1]), down = min(down, now - cl[i - 1]);
        f[i] = now, s[i] = now - up;
        now -= up;
    }
    for(int i = 1; i <= n; i++) cout << s[i] <<" " << f[i] << endl;
    return 0;
}