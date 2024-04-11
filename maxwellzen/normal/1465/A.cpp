#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, n;
string s;

void solve() {
    cin >> n;
    int last = n;
    bool prev = false;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c==')') {
            if (! prev) last = i;
            prev=true;
        } else prev = false;
    }
    if (c==')' && n-last>last) cout << "Yes\n";
    else cout << "No\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}