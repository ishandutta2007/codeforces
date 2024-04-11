#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
ll k;
int a[Maxn];
vector <int> un;
int BIT1[Maxn], BIT2[Maxn];
ll cur;
ll res;

void addLarge(int BIT[], int x, int val)
{
    x++;
    for (int i = x; i > 0; i -= i & -i)
        BIT[i] += val;
}

int getLarge(int BIT[], int x)
{
    x++;
    int res = 0;
    for (int i = x + 1; i <= un.size(); i += i & -i)
        res += BIT[i];
    return res;
}

void addSmall(int BIT[], int x, int val)
{
    x++;
    for (int i = x; i <= un.size(); i += i & -i)
        BIT[i] += val;
}

int getSmall(int BIT[], int x)
{
    x++;
    int res = 0;
    for (int i = x - 1; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    scanf("%d %I64d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        un.push_back(a[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(un.begin(), un.end(), a[i]) - un.begin();
    for (int i = n - 1; i >= 0; i--) {
        cur += getSmall(BIT2, a[i]);
        addSmall(BIT2, a[i], 1);
    }
    if (cur <= k) {
        printf("%I64d\n", ll(n) * (n - 1) / 2ll);
        return 0;
    }
    int r = 0;
    while (cur > k) {
        cur -= getSmall(BIT2, a[r]);
        addSmall(BIT2, a[r], -1);
        r++;
    }
    for (int i = 0; i < n; i++) {
        cur += getLarge(BIT1, a[i]) + getSmall(BIT2, a[i]);
        addLarge(BIT1, a[i], 1);
        while (cur > k && r < n) {
            cur -= (getLarge(BIT1, a[r]) + getSmall(BIT2, a[r]));
            addSmall(BIT2, a[r], -1);
            r++;
        }
        res += n - r;
    }
    printf("%I64d\n", res);
    return 0;
}