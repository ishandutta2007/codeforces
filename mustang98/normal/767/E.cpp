#include <bits/stdc++.h>

#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

const int max_n = 100111;
int c[max_n], w[max_n], n;
long long sum, nedov = 0;
vector<pair<int, int> > cost;
set<pair<int, int> > sett;
pair<int, int> ans[max_n];

int main() {
    scanf("%d%d", &n, &sum);
    for (int i = 0; i < n; ++i) {
        scanf("%d", c + i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", w + i);
        if (c[i] % 100 == 0) {
            ans[i].F = c[i] / 100;
            ans[i].S = 0;
            continue;
        }
        int ned = w[i] * (100 - (c[i] % 100));
        cost.pb(mp(ned, i));
    }
    for (pair<int, int> p : cost) {
        sett.insert(p);
        sum -= c[p.S] % 100;
        ans[p.S].F = c[p.S] / 100;
        ans[p.S].S = c[p.S] % 100;
        if (sum < 0) {
            sum += 100;
            nedov += sett.begin()->F;
            ans[sett.begin()->S].F++;
            ans[sett.begin()->S].S = 0;
            sett.erase(sett.begin());
        }
    }
    printf("%I64d\n", nedov);
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", ans[i].F, ans[i].S);
    }
    return 0;
}