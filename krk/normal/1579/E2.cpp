#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
vector <int> un;
int BIT[Maxn];

void Insert(int x)
{
    for (int i = x + 1; i <= un.size(); i += i & -i)
        BIT[i]++;
}

int Get(int x)
{
    int res = 0;
    for (int i = x + 1; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int Get(int l, int r)
{
    if (l > r) return 0;
    return Get(r) - Get(l - 1);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        un.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            un.push_back(a[i]);
        }
        sort(un.begin(), un.end());
        un.erase(unique(un.begin(), un.end()), un.end());
        fill(BIT, BIT + int(un.size()) + 1, 0);
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
            res += min(Get(0, ind - 1), Get(ind + 1, int(un.size()) - 1));
            Insert(ind);
        }
        printf("%I64d\n", res);
    }
    return 0;
}