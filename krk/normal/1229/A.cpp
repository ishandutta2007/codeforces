#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 7005;

int n;
ll mask[Maxn];
int a[Maxn];
int bet[Maxn];
set <int> S;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &mask[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for (int j = 0; j < n; j++) if (i != j)
            if ((mask[i] & mask[j]) != mask[i])
                bet[i]++;
        S.insert(i);
    }
    bool rep = true;
    while (rep) {
        rep = false;
        for (set <int>::iterator it = S.begin(); it != S.end(); )
            if (bet[*it] == int(S.size()) - 1) {
                rep = true;
                int ind = *it;
                S.erase(it++);
                for (set <int>::iterator it2 = S.begin(); it2 != S.end(); it2++)
                    if ((mask[*it2] & mask[ind]) != mask[*it2])
                        bet[*it2]--;
            } else it++;
    }
    ll res = 0;
    for (set <int>::iterator it = S.begin(); it != S.end(); it++)
        res += a[*it];
    cout << res << endl;
    return 0;
}