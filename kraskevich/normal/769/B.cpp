#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
#if FALSE
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    vector<pii> ans;
    for (int i = 1; i < n; i++) {
        int v = -1;
        for (int j = 0; j < i; j++)
            if (a[j].first > 0) {
                v = j;
                break;
            }
        if (v == -1) {
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(pii(a[v].second, a[i].second));
        a[v].first--;
    }
    cout << ans.size() << endl;
    for (auto p : ans)
        cout << p.first + 1 << " " << p.second + 1 << endl;
}