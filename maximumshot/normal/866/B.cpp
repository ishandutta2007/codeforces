#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

int const inf = 1e9;
ll const inf64 = 1e18;

int const N = 1e5 + 5;

int n, S;
int s[N];
int a[N];
int b[N];
ll tot;
ll cnt;
int perm[N];
ll sumB;

ll f(ll u, ll v) {
    return (u + v - 1) / v;
}

ll func(ll k) {
    return f(k, S) + f(tot - k, S);
}

pair< ll, ll > get(ll tmpcnt, ll LEN) {
    ll md = ((-tmpcnt) % S + S) % S;
    if(md == 0) md = S;
    // k * md > 0
    ll kl = md;
    // k * md < LEN
    ll kr = LEN % md ? LEN / md : LEN / md - 1;
    if(kl <= kr && kl * md > 0 && kr * md < LEN) {
    }else {
        kl = -1;
        kr = -1;
    }

    ll kr2, kl2;
    kl2 = kr2 = -1;

    md = ((tot - tmpcnt) % S + S) % S;

    if(md == 0) md = S;

    kl2 = md;
    kr2 = LEN % md ? LEN / md : LEN / md - 1;

    if(kl2 <= kr2 && kl2 * md > 0 && kr2 * md < LEN) {
    }else {
        kl2 = kr2 = -1;
    }

    if(kl2 == -1) {
        return make_pair(kl, kr);
    }else if(kl == -1) {
        return make_pair(kl2, kr2);
    }else {
        return make_pair(min(kl, kl2), max(kr, kr2));
    }
}

ll simple() {
    vec< int >  arr;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < s[i];j++) {
            arr.push_back(a[i] - b[i]);
        }
    }
    sort(ALL(arr));
    reverse(ALL(arr));
    ll res = 0;
    ll tmp = 0;
    for(int i = 0;i < (int)arr.size();i++) {
        tmp += arr[i];
        int k = i + 1;
        if(func(k) == cnt) {
            if(tmp + sumB == 314) {
                cout << i + 1 << "?\n";
            }
            res = max(res, tmp + sumB);
        }
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &S);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d %d", &s[i], &a[i], &b[i]);
        tot += s[i];
        perm[i] = i;
        sumB += 1ll * s[i] * b[i];
    }

    cnt = (tot + S - 1) / S;

//    cout << cnt << "\n";

//    for(int i = 1;i <= tot;i++) {
//        cout << i << " : " << func(i) << "\n";
//    }

    sort(perm + 1, perm + n + 1, [&](int i, int j) {
        return a[i] - b[i] > a[j] - b[j];
    });

    ll res = 0;

    {
        ll tmp1 = 0;
        ll tmp2 = 0;
        for(int i = 1;i <= n;i++) {
            tmp1 += 1ll * s[i] * a[i];
            tmp2 += 1ll * s[i] * b[i];
        }
        res = max(tmp1, tmp2);
    }

    {
        ll tmpres = 0;
        ll tmpcnt = 0;
        for(int iter = 1;iter <= n;iter++) {
            int i = perm[iter];
            tmpres += 1ll * s[i] * (a[i] - b[i]);
            tmpcnt += s[i];
            if(func(tmpcnt) <= cnt) {
                res = max(res, tmpres + sumB);
            }
        }
    }

    ll tmpres = 0;
    ll tmpcnt = 0;
    int iter;

    for(iter = 1;iter <= n;iter++) {
        int i = perm[iter];
        if(a[i] - b[i] >= 0) {
            tmpres += 1ll * s[i] * (a[i] - b[i]);
            tmpcnt += s[i];
        }else {
            break;
        }
    }

    ll lasttmpcnt = tmpcnt - tmpcnt % S;

    tmpcnt %= S;

    iter--;

    vec< int > arr;

    for(int j = iter + 1;j <= n;j++) {
        for(int i = 0;i < s[perm[j]] && (int)arr.size() <= S;i++) {
            arr.push_back(a[perm[j]] - b[perm[j]]);
        }
    }

    while(tmpcnt > 0) {
        for(int j = 0;j < s[perm[iter]] && tmpcnt > 0;j++) {
            arr.push_back(a[perm[iter]] - b[perm[iter]]);
            tmpcnt--;
            tmpres -= a[perm[iter]] - b[perm[iter]];
        }
        iter--;
    }

    sort(ALL(arr));
    reverse(ALL(arr));

    res = max(res, tmpres + sumB);

    ll cur = 0;
    for(int j = 0;j < (int)arr.size();j++) {
        cur += arr[j];
        if(func(lasttmpcnt + j + 1) <= cnt) {
            res = max(res, tmpres + cur + sumB);
        }
    }

    cout << res << "\n";

    return 0;
}