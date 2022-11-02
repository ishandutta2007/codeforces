#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN (200 * 1000)

int n;
ll k, a[MAXN];

ll calc()
{
    map<ll, int> cnt_l, cnt_r;
    for (int i = n; --i > 0; ) {
//        cerr << "add " << i << endl;
        if (a[i] % k == 0) cnt_r[a[i] / k]++;
    }

    ll ret = 0;
    for (int i = 1; i < n; i++) {
//        cerr << "remove " << i << endl;
        if (a[i] % k == 0) cnt_r[a[i] / k]--;
//        cerr << "add left " << (i - 1) << endl;
        cnt_l[a[i - 1] * k]++;
        ret += 1LL * cnt_l[a[i]] * cnt_r[a[i]];
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    while(cin >> n >> k) {
#else
    if(cin >> n >> k) {
#endif // LOCAL
        for(int i = 0; i < n; i++) cin >> a[i];

        if (n < 3) {
            cout << "0" << endl;
        } else {
            cout << calc() << endl;
        }
    }
    return 0;
}