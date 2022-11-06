#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, q, a[N];
set<int> s[N];

int main() {
    
    scanf("%d %d", &n, &q);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[a[i]].insert(i);
        mx = max(mx, a[i]);
    }
    vector<pair<pair<int, int>, int> > events;
    for (int i = 1; i <= mx; i++) {
        if (s[i].empty()) continue;
        int from = *s[i].begin();
        int to = *s[i].rbegin();
        int size = s[i].size();
        events.push_back({{from, to}, size});
    }
    sort(events.begin(), events.end());
    int furthest = 0;
    int ans = 0;
    mx = 0;
    for (auto event : events) {
        if (event.first.first > furthest) {
            ans += mx;
            mx = 0;
        }
        mx = max(mx, (int)event.second);
        furthest = max(furthest, event.first.second);
    }
    ans += mx;
    printf("%d\n", n - ans);
    return 0;
}