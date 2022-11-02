#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x != 0)
            s.insert(x);
    }
    cout << s.size() << endl;

}