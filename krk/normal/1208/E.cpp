#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 1000005;

ll delt[Maxn];
ii a[Maxn];
set <ii> S;
int n, w;

ii Get(int lef, int rig)
{
    int mylef = lef, myrig = rig;
    set <ii>::iterator it2 = S.lower_bound(ii(lef + 1, 0));
    set <ii>::iterator it = it2;
    while (it != S.begin()) {
        it--;
        if (it->second >= lef) {
            mylef = max(mylef, it->second + 1);
            lef = min(lef, it->first);
            rig = max(rig, it->second);
            S.erase(it++);
        } else break;
    }
    while (it2 != S.end() && rig >= it2->first) {
        myrig = min(myrig, it2->first - 1);
        lef = min(lef, it2->first);
        rig = max(rig, it2->second);
        S.erase(it2++);
    }
    S.insert(ii(lef, rig));
    return ii(mylef, myrig);
}

int main()
{
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; i++) {
        int l; scanf("%d", &l);
        int s = w - l;
        for (int j = 0; j < l; j++) {
            scanf("%d", &a[j].first);
            a[j].second = j;
        }
        sort(a, a + l);
        S.clear();
        bool neg = false;
        for (int j = l - 1; j >= 0; j--) {
            if (a[j].first < 0 && !neg) {
                if (s > 0) {
                    Get(0, s - 1);
                    Get(w - s, w - 1);
                }
                neg = true;
            }
            ii got = Get(a[j].second, a[j].second + s);
            if (got.first <= got.second) {
                delt[got.first] += a[j].first;
                delt[got.second + 1] -= a[j].first;
            }
        }
    }
    ll cur = 0;
    for (int i = 0; i < w; i++) {
        cur += delt[i];
        printf("%I64d%c", cur, i + 1 < w? ' ': '\n');
    }
    return 0;
}