#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
vector <int> one[Maxn], two[Maxn];
int l, r;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &l, &r);
        for (int i = l; i <= r; i++) {
            one[i].clear();
            two[i].clear();
        }
        ll res = 0;
        for (int i = l; i <= r; i++) {
            for (int j = i + i; j <= r; j += i) {
                res += one[j].size();
                res += two[j].end() - upper_bound(two[j].begin(), two[j].end(), j - i);
                one[j].push_back(i);
            }
            if (i % 2 == 0)
                for (int j = i + i / 2; j <= r; j += i) {
                    res += one[j].end() - upper_bound(one[j].begin(), one[j].end(), j - i);
                    res += two[j].end() - upper_bound(two[j].begin(), two[j].end(), j - i);
                    two[j].push_back(i);
                }
        }
        ll sz = r - l + 1;
        res = sz * (sz - 1) * (sz - 2) / 6 - res;
        printf("%I64d\n", res);
    }
    return 0;
}