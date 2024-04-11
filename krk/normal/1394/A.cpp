#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, d, m;
vector <int> big, small;
ll sum[Maxn];

ll getAll(int sub)
{
    if (sub >= small.size()) return 0;
    return sum[int(small.size()) - 1] - (sub? sum[sub - 1]: 0);
}

int main()
{
    scanf("%d %d %d", &n, &d, &m);
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        if (a > m) big.push_back(a);
        else small.push_back(a);
    }
    sort(small.begin(), small.end());
    sort(big.begin(), big.end());
    for (int i = 0; i < small.size(); i++) {
        sum[i] = small[i];
        if (i > 0) sum[i] += sum[i - 1];
    }
    ll res = 0;
    if (!small.empty()) res = getAll(0);
    ll add = 0;
    for (int i = 1; i <= big.size(); i++) {
        add += big[int(big.size()) - i];
        ll tk = (i - 1) * d + i;
        if (tk <= big.size()) res = max(res, add + getAll(0));
        else if (tk <= big.size() + small.size()) res = max(res, add + getAll(tk - int(big.size())));
    }
    printf("%I64d\n", res);
    return 0;
}