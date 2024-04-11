#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int cnt[max_n];
int n, s, f;
ll sum[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cnt[i];
    }
    cin >> s >> f;
    --s, --f;

    ll max_cnt = -5;
    int tm = -1;

    ll cur_sum = 0;
    for (int i = s; i < f; ++i) {
        cur_sum += cnt[i];
    }

    max_cnt = cur_sum;
    tm = 1;

    for (int i = 2; i <= n; ++i) {
        --f, --s;
        if (s < 0) s = n - 1;
        if (f < 0) f = n - 1;
        cur_sum += cnt[s];
        cur_sum -= cnt[f];
        if (cur_sum > max_cnt) {
            max_cnt = cur_sum;
            tm = i;
        }
    }
    cout << tm;
    return 0;
}