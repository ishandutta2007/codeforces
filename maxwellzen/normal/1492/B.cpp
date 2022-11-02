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

void solve() {
    cin >> n;
    vi p(n);
    set<int> cards;
    for (int i = 0; i < n; i++) {cin >> p[i]; cards.insert(i+1);}
    vi next;
    for (int i = n-1; i >= 0; i--) {
        next.pb(p[i]);
        if (p[i]==*--cards.end()) {
            for (int j = next.size()-1; j >= 0; j--) cout << next[j] << ' ';
            next.clear();
        }
        cards.erase(p[i]);
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}