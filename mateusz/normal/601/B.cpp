#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18, N = 100005;

int n, q, l, r;
int tab[N];

int main() {

    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }

    while (q--) {
        scanf("%d %d", &l, &r);
        vector<pair<long long, int> > maxes;
        maxes.push_back({INF, l - 1});
        long long ans = 0;
        long long sum = 0;
        for (int i = l + 1; i <= r; i++) {
            int a = abs(tab[i] - tab[i - 1]);
            while (maxes.back().first < a) {
                long long val = maxes.back().first;
                long long pos = maxes.back().second;
                maxes.pop_back();
                sum -= (pos - maxes.back().second) * val;
            }
            int myPos = i - 1;
            sum += (long long)(myPos - maxes.back().second) * a;
            maxes.push_back({a, i - 1});
            ans += sum;
        }
        printf("%lld\n", ans);
    }

    return 0;
}