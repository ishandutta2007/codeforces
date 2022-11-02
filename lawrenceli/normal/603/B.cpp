#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 1000100;
const int mod = 1e9 + 7;

int p, k;
bool vis[maxn];

void dfs(int cur) {
    if (vis[cur]) return;
    vis[cur] = 1;
    dfs(ll(k) * cur % p);
}

int pw(int a, int b) {
    int ret = 1;
    for (int i = 0; i < b; i++)
        ret = ll(ret) * a % mod;
    return ret;
}

int main() {
    cin >> p >> k;

    if (k == 0) cout << pw(p, p-1) << '\n';
    else if (k == 1) cout << pw(p, p) << '\n';
    else {
        int cnt = 0;
        for (int i = 1; i < p; i++)
            if (!vis[i]) {
                cnt++;
                dfs(i);
            }

        cout << pw(p, cnt) << '\n';
    }
}