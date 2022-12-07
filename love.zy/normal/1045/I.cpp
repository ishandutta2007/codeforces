#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

char buf[1000010];

const int maxn = 100010;

int cnt[maxn], val[maxn], n = 0;
map<int, int> mp;

typedef long long ll;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", buf);
        int len = int(strlen(buf));
        for (int j = 0; j < len; j++) {
            int t = buf[j]-'a';
            val[i] ^= (1<<t);
        }
        mp[val[i]] ++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += mp[val[i]]-1;
        for (int j = 0; j < 26; j++) {
            ans += mp[val[i]^(1<<j)];
        }
    }
    cout << ans/2 << endl;
    return 0;
}