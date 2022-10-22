#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int Maxn = 100005;
const int Maxm = 12;

int arg1, arg2;
int pw1[Maxn], pw2[Maxn];
int n, m;
int a[Maxm][Maxn];
ii H[Maxm][Maxn];
vector <int> has[Maxn];
ll res;

ii Get(ii H[], int l, int r)
{
    ii res = H[r];
    l--;
    if (l >= 0) {
        res.first = (res.first - ll(H[l].first) * pw1[r - l] % mod1 + mod1) % mod1;
        res.second = (res.second - ll(H[l].second) * pw2[r - l] % mod2 + mod2) % mod2;
    }
    return res;
}

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    srand(time(0));
    arg1 = rand() % 128;
    while (!Prime(arg1)) arg1++;
    arg2 = rand() % 256;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        ii h = ii(0, 0);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            h.first = (ll(h.first) * arg1 + ll(a[i][j])) % mod1;
            h.second = (ll(h.second) * arg2 + ll(a[i][j])) % mod2;
            H[i][j] = h;
            has[a[i][j]].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) {
        int lef = 2, rig = n;
        for (int j = 0; j < has[i].size(); j++)
            rig = min(rig, n - has[i][j]);
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            ii cur = Get(H[0], has[i][0], has[i][0] + mid - 1);
            bool eq = true;
            for (int j = 1; j < m && eq; j++)
                eq = cur == Get(H[j], has[i][j], has[i][j] + mid - 1);
            if (eq) lef = mid + 1;
            else rig = mid - 1;
        }
        lef--;
        res += lef;
    }
    printf("%I64d\n", res);
    return 0;
}