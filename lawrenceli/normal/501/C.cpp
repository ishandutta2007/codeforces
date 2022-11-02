#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1<<16;

int n, deg[MAXN], s[MAXN];

typedef pair<int, int> pii;
set<pii> st;
vector<pii> ans;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> deg[i] >> s[i];
        st.insert(pii(deg[i], i));
    }

    while (!st.empty()) {
        pii p = *st.begin();
        assert(p.first <= 1);
        st.erase(p);
        if (!p.first) continue;
        int x = s[p.second];
        ans.push_back(pii(p.second, x));
        s[x] ^= p.second, deg[x]--;
        st.erase(pii(deg[x]+1, x)); st.insert(pii(deg[x], x));
    }

    cout << ans.size() << endl;
    for (int i=0; i<ans.size(); i++) cout << ans[i].first << ' ' << ans[i].second << endl;
}