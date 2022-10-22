#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;

int T;
int n;
multiset <ll> A, B;
vector <ll> un;
ll p1, p2;
ll res[Maxn];

bool solveX(ll x)
{
    multiset <ll> S1 = A;
    multiset <ll> S2 = B;
    for (int i = 0; i < n; i++) {
        auto it1 = S1.end(); it1--;
        auto it2 = S2.end(); it2--;
        if (*it1 >= *it2) {
            res[i] = *it1;
            ll nd = *it1 <= x? x - *it1: *it1 - x;
            auto fit = S2.find(nd);
            if (fit == S2.end()) return false;
            S1.erase(it1);
            S2.erase(fit);
        } else {
            res[i] = x - *it2;
            ll nd = *it2 <= x? x - *it2: *it2 - x;
            auto fit = S1.find(nd);
            if (fit == S1.end()) return false;
            S1.erase(fit);
            S2.erase(it2);
        }
    }
    return true;
}

void Solve()
{
    for (int i = 0; i < un.size(); i++)
        if (solveX(un[i])) {
            ll mn = 0;
            for (int j = 0; j < n; j++)
                mn = min(mn, res[j]);
            printf("YES\n");
            for (int j = 0; j < n; j++)
                printf("%I64d%c", res[j] - mn, j + 1 < n? ' ': '\n');
            printf("%I64d %I64d\n", -mn, un[i] - mn);
            return;
        }
    printf("NO\n");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        A.clear(); B.clear();
        un.clear();
        for (int i = 0; i < n; i++) {
            int d; scanf("%d", &d);
            A.insert(d);
        }
        for (int i = 0; i < n; i++) {
            int d; scanf("%d", &d);
            B.insert(d);
        }
        ll me = *A.begin();
        for (auto el: B) {
            un.push_back(el + me);
            un.push_back(abs(el - me));
        }
        sort(un.begin(), un.end());
        un.erase(unique(un.begin(), un.end()), un.end());
        Solve();
    }
    return 0;
}