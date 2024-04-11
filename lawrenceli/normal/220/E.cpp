#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

const int MAXN = 100010;

int n, a[MAXN], cnt, bit[MAXN], inv[MAXN], l, r = 1;
ll k, tot, val, ans;
map<int, int> mp;

int query(int i) {
    int ret = 0;
    for (i+=2; i>0; i-=i&-i) ret += bit[i];
    return ret;
}

void update(int i, int p) {
    for (i+=2; i<MAXN; i+=i&-i) bit[i] += p;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %I64d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]] = 0;
    }
    for (typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++) {
        mp[it->first] = cnt++;
    }
    for (int i=0; i<n; i++) a[i] = mp[a[i]];
    for (int i=0; i<n; i++) {
        inv[i] += i - query(a[i]);
        update(a[i], 1);
    }
    for (int i=0; i<MAXN; i++) bit[i] = 0;
    for (int i=n-1; i>=0; i--) {
        inv[i] += query(a[i]-1);
        update(a[i], 1);
    }
    for (int i=0; i<n; i++) tot += inv[i];
    tot /= 2;
    val = tot;
    for (int i=0; i<MAXN; i++) bit[i] = 0;
    while (l<n) {
        if (r <= l || r<n && val > k) {
            val -= inv[r] - (r - l - 1- query(a[r]));
            update(a[r++], 1);
        }
        else {
            ans += n - r;
            val += inv[l+1] - query(a[l+1] - 1);
            update(a[(l++)+1], -1);
        }
    }
    printf("%I64d\n", ans);
}