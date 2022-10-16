#include <bits/stdc++.h>

using namespace std;

int n;
pair <long long, long long> a[100005];

bool bad(int u, int v, int t) {
    if (a[t].first == a[v].first) return 1;
    return (a[u].second - a[v].second) * (a[t].first - a[v].first)
        >= (a[v].second - a[t].second) * (a[v].first - a[u].first);
}

vector <int> s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        long long x, y;
        cin >> x >> y;
        a[i].first = -x;
        a[i].second = y - x * x;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        while (s.size() > 0 && a[s.back()].first == a[i].first) s.pop_back();
        while (s.size() > 1 && bad(s[s.size() - 2], s[s.size() - 1], i)) s.pop_back();
        s.push_back(i);
    }
    cout << s.size() - 1 << endl;
    return 0;
}