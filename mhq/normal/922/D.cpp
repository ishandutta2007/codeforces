#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int n;
string t[maxN];
int a[maxN];
int h[maxN];
int s[maxN];
long long get(string t) {
    long long ans = 0;
    long long s = 0;
    long long h = 0;
    for (int i = 0; i < t.size(); i++) {
        h += (t[i] == 'h');
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 's') ans += h;
        if (t[i] == 'h') h--;
    }
    return ans;
}
bool cmp(int i, int j) {
    return ((1LL * s[i] * h[j]) > (1LL * s[j] * h[i]));
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        a[i] = i;
        for (int j = 0; j < t[i].size(); j++) {
            if (t[i][j] == 's') s[i]++;
            else h[i]++;
        }
        ans += get(t[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    long long suf = 0;
    for (int i = 1; i <= n; i++) {
        suf += h[a[i]];
    }
    for (int i = 1; i <= n; i++) {
        suf -= h[a[i]];
        ans += s[a[i]] * suf;
    }
    cout << ans;
    return 0;
}