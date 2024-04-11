#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> deg(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        deg[v]++;
        deg[u]++;
    }

    if (n == 2) {
        cout << "Yes\n";
        return 0;
    }
    if (*max_element(all(deg)) == 2) {
        cout << "No\n";
        return 0;
    }
    if (find(all(deg), 2) != deg.end()) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
}