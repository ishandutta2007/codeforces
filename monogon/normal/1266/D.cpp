
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, m, u, v;
ll d;
ll bal[N];
set<int> s1, s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> d;
        u--; v--;
        bal[u] -= d;
        bal[v] += d;
    }
    vector<tuple<int, int, ll>> debt;
    for(int i = 0; i < n; i++) {
        if(bal[i] < 0) s1.insert(i);
        else if(bal[i] > 0) s2.insert(i);
    }
    while(s1.size()) {
        u = *s1.begin();
        v = *s2.begin();
        d = min(-bal[u], bal[v]);
        debt.emplace_back(u, v, d);
        if(d == -bal[u]) s1.erase(s1.begin());
        if(d == bal[v]) s2.erase(s2.begin());
        bal[u] += d;
        bal[v] -= d;
    }
    cout << debt.size() << endl;
    for(auto p : debt) {
        tie(u, v, d) = p;
        cout << u + 1 << " " << v + 1 << " " << d << endl;
    }
}