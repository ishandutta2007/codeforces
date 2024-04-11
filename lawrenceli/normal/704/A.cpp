#include <bits/stdc++.h>

using namespace std;

const int maxn = 300100;

int n, q, num;
set<int> st;
vector<int> v[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> q;
    int cnt = 1;
    for (int i = 0; i < q; i++) {
        int t, x; cin >> t >> x;
        if (t == 1) {
            st.insert(cnt);
            v[x].push_back(cnt);
            cnt++;
            num++;
        } else if (t == 2) {
            for (int j : v[x]) {
                if (st.count(j)) st.erase(j), num--;
            }
            v[x].clear();
        } else {
            while (!st.empty()) {
                int a = *st.begin();
                if (a <= x) st.erase(a), num--;
                else break;
            }
        }

        cout << num << '\n';
    }
}