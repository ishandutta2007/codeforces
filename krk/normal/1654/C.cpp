#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
map <ll, int> M;

bool Solve()
{
    while (!M.empty()) {
        auto it = M.end(); it--;
        if (it->second < 0 || it->first == 1 && it->second != 0) return false;
        if (it->second > 0) {
            ll a = (it->first + 1) / 2;
            ll b = (it->first) / 2;
            M[a] += it->second;
            M[b] += it->second;
        }
        M.erase(it);
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        M.clear();
        scanf("%d", &n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            M[a[i]]--;
            sum += a[i];
        }
        M[sum]++;
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}