#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, k;
vector <int> both;
vector <int> a;
vector <int> b;

int main () {
    scanf("%d %d", &n, &k);

    for (int i = 1 ; i <= n ; ++ i) {
        int t, la, lb;
        scanf("%d %d %d", &t, &la, &lb);
        if (la && lb) {
            both.push_back(t);
        } else if (la){
            a.push_back(t);
        } else if (lb) {
            b.push_back(t);
        }
    }

    sort(both.begin(), both.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto pref_sum = [&] (vector <int> &v) -> void {

        for (int i = 1 ; i < v.size() ; ++ i)
            v[i] += v[i - 1];
    };

    pref_sum(both);
    pref_sum(a);
    pref_sum(b);

    long long ans = LLONG_MAX;

    if (min(int(a.size()), int(b.size())) >= k) {
        ans = min(ans, 0LL + a[k - 1] + b[k - 1]);
    }

    for (int i = 0 ; i < both.size() ; ++ i) {
        long long c = both[i];
        int need = max(0, k - i - 1);

        if (min(int(a.size()), int(b.size())) >= need) {
            if (need) {
                c += a[need - 1] + b[need - 1];
            }
            ans = min(ans, c);
        }

    }

    printf("%lld\n", ans == LLONG_MAX ? -1LL : ans);
}