#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long;
int n, m, d;
int a[nax];
int b = 0;
int g;
vector <int> good;
vector <int> small;
vector <ll> sum_good;
vector <ll> sum_small;

vector <ll> to_pref_sum (vector <int> in) {
    vector <ll> res;
    res.resize(in.size());
    if (in.empty()) return res;
    res[0] = in[0];
    for (int i = 1 ; i < in.size() ; ++ i) {
        res[i] = res[i - 1] + in[i];
    }
    return res;
}

int main () {
    scanf("%d %d %d", &n, &d, &m);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
        if (a[i] <= m) ++ b;
        else ++ g;
        if (a[i] > m) good.push_back(a[i]);
        else small.push_back(a[i]);
    }

    sort(good.begin(), good.end(), greater <int>());
    sort(small.begin(), small.end(), greater <int>());

    sum_good = to_pref_sum(good);
    sum_small = to_pref_sum(small);


    long long ans = 0;

    for (int cg = 0 ; cg <= g; ++ cg) {
        long long sum = 0;
        long long max_bound = 1LL * cg * d;
        long long min_bound = 1LL * (cg - 1) * d;
        if (min_bound > n) continue;
        int has = g - cg;
        if (has > max_bound) continue;

        if (has >= min_bound) {
            min_bound = has;
        }

        long long pay_small = min_bound - has;
        if (pay_small > b) continue;
        int res_small = b;
        res_small -= pay_small;

        ll cur = cg ? sum_good[cg - 1] : 0;
        cur += res_small == 0 ? 0 : sum_small[res_small - 1];
        ans = max(ans, cur);
    }

    printf("%lld\n", ans);
}