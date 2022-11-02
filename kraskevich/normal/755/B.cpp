#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    set<string> a;
    set<string> b;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.insert(s);    
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        b.insert(s);
    }
    int both = 0;
    for (auto& s : a)
        if (b.count(s))
            both++;
    n -= both;
    m -= both;
    if (n + (both + 1) / 2 > m + (both - (both + 1) / 2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}