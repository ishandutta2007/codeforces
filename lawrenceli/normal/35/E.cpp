#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <ios>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, bool> piib;

const int MAXN = 100100;

int n;
piib ar[2*MAXN];

int main() {
    ios :: sync_with_stdio(0);
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    cin >> n;
    for (int i=0; i<n; i++) {
        int h, l, r;
        cin >> h >> l >> r;
        ar[2*i] = piib(pii(l, h), 0);
        ar[2*i+1] = piib(pii(r, h), 1);
    }
    sort(ar, ar+2*n);

    multiset<int> st;
    vector<pii> ans, ans2;
    st.insert(0);
    ans2.push_back(pii(ar[0].fi.fi, 0));
    for (int i=0; i<2*n; i++) {
        if (ar[i].se) st.erase(st.find(ar[i].fi.se));
        else st.insert(ar[i].fi.se);
        int h = *st.rbegin();
        ans2.push_back(pii(ar[i].fi.fi, ans2.back().se));
        ans2.push_back(pii(ar[i].fi.fi, h));
    }
    for (int i=0, j; i<ans2.size(); i = max(i+1, j-1)) {
        for (j=i; j<ans2.size() && ans2[j].se == ans2[i].se; j++);
        ans.push_back(ans2[i]);
    }
    ans2 = ans;
    ans.clear();
    for (int i=0, j; i<ans2.size(); i = max(i+1, j-1)) {
        for (j=i; j<ans2.size() && ans2[j].fi == ans2[i].fi; j++);
        ans.push_back(ans2[i]);
    }

    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); i++)
        cout << ans[i].fi << ' ' << ans[i].se << '\n';
    return 0;
}