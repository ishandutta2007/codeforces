#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 9000000000000000000ll;
const int Maxn = 100005;
const int Maxm = 5;

int T;
int n;
int a[Maxn];
vector <int> pos, neg;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        pos.clear(); neg.clear();
        bool zer = false;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > 0) pos.push_back(a[i]);
            else if (a[i] < 0) neg.push_back(a[i]);
            else zer = true;
        }
        sort(pos.begin(), pos.end());
        sort(neg.rbegin(), neg.rend());
        ll res = -Inf;
        if (zer) res = 0;
        for (int i = 0; i <= 5 && i <= pos.size(); i++) {
            int j = 5 - i;
            if (j > neg.size()) continue;
            if (j % 2) {
                ll cur = 1;
                for (int z = 0; z < i; z++)
                    cur *= pos[z];
                for (int z = 0; z < j; z++)
                    cur *= neg[z];
                res = max(res, cur);
            } else {
                ll cur = 1;
                for (int z = 1; z <= i; z++)
                    cur *= pos[int(pos.size()) - z];
                for (int z = 1; z <= j; z++)
                    cur *= neg[int(neg.size()) - z];
                res = max(res, cur);
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}