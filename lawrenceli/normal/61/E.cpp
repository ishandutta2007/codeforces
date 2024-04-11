#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 1000100;

int n, a[MAXN];
ll bit[2][MAXN], ans;

void update(int c, int i, ll v) {
    for (i++; i<MAXN; i+=i&-i) bit[c][i] += v;
}

ll query(int c, int i) {
    ll ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[c][i];
    return ret;
}

map<int, int> mp;
int cnt;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]] = 0;
    }
    for (typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++)
        mp[it->first] = cnt++;
    for (int i=0; i<n; i++) a[i] = mp[a[i]];

    for (int i=n-1; i>=0; i--) {
        update(0, a[i], 1);
        update(1, a[i], query(0, a[i]-1));
        ans += query(1, a[i]-1);
    }
    cout << ans << '\n';
    return 0;
}