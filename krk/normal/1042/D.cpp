#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
ll t;
ll a[Maxn];
int BIT[Maxn];
vector <ll> un;

void Insert(int x)
{
    for (int i = x + 1; i > 0; i -= i & -i)
        BIT[i]++;
}

int Get(int x)
{
    int res = 0;
    for (int i = x + 1; i < Maxn; i += i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    scanf("%d %I64d", &n, &t);
    un.push_back(0);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        a[i] += a[i - 1];
        un.push_back(a[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    ll res = 0;
    int ind = lower_bound(un.begin(), un.end(), 0ll) - un.begin();
    Insert(ind);
    for (int i = 1; i <= n; i++) {
        ind = upper_bound(un.begin(), un.end(), a[i] - t) - un.begin();
        res += Get(ind);
        ind = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
        Insert(ind);
    }
    printf("%I64d\n", res);
    return 0;
}