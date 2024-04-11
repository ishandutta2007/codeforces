#include <bits/stdc++.h>

using namespace std;

const int MAXN = 305;

int n, a[MAXN], b[MAXN];

int gcd(int x, int y) {
    if (!x) return y;
    return gcd(y%x, x);
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    map<int, int> mp;
    mp[0] = 0;
    for (int i=0; i<n; i++) {
        map<int, int> mp2;
        for (map<int, int>::iterator j=mp.begin(); j!=mp.end(); j++) {
            int x = gcd(j->first, a[i]);
            if (!mp2.count(x)) mp2[x] = j->second+b[i];
            else mp2[x] = min(mp2[x], j->second+b[i]);
        }
        for (map<int, int>::iterator j=mp2.begin(); j!=mp2.end(); j++) {
            if (!mp.count(j->first)) mp[j->first] = j->second;
            else mp[j->first] = min(mp[j->first], j->second);
        }
    }

    if (!mp.count(1)) cout << -1;
    else cout << mp[1] << '\n';
    return 0;
}