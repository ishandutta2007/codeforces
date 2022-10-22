#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Inf = 1000000000;
const int Maxn = 500005;

int T;
int n;
int a[Maxn];
map <ll, int> M;
map <ll, int> my;
int dp[Maxn];

void Insert(ll key, int val)
{
    auto it = M.upper_bound(key);
    if (it != M.begin()) {
        it--;
        if (it->second >= val) return;
    }
    it = M.lower_bound(key);
    while (it != M.end() && val >= it->second)
        M.erase(it++);
    M.insert(make_pair(key, val));
}

int Get(ll key)
{
    auto it = M.lower_bound(key);
    if (it == M.begin()) return -Inf;
    it--;
    return it->second;
}

void insertMy(ll key, int val)
{
    auto it = my.find(key);
    if (it == my.end()) my.insert(make_pair(key, val));
    else it->second = max(it->second, val);
}

int getMy(ll key)
{
    auto it = my.find(key);
    return it == my.end()? -Inf: it->second;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        M.clear(); my.clear();
        ll cur = 0;
        Insert(cur, 0);
        insertMy(cur, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            cur += a[i];
            dp[i] = max(dp[i - 1] - 1, max(Get(cur) + i, getMy(cur)));
            Insert(cur, dp[i] - i);
            insertMy(cur, dp[i]);
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}