
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int dsu[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int t, n, k;
string s;
multiset<char> se[N];

int solve(multiset<char> s) {
    int ans = s.size();
    int sz1 = ans;
    while(s.size()) {
        int sz = s.size();
        s.erase(*s.begin());
        ans = min(ans, sz1 - (sz - (int) s.size()));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        fill(dsu, dsu + n, -1);

        for(int i = 0; i < n - k; i++) {
            join(i, i + k);
        }
        for(int i = 0; i < n; i++) {
            join(i, n - i - 1);
        }
        for(int i = 0; i < n; i++) {
            se[trace(i)].insert(s[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += solve(se[i]);
            se[i].clear();
        }
        cout << ans << endl;
    }
}