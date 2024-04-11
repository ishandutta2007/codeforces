
#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    vi ve;
    ll n = 1;
    while(n * (n - 1) / 2 < k) n++;
    for(ll i = n; i > 0 && k > 0; i--) {
        if(i * (i - 1) / 2 <= k) {
            k -= i * (i - 1) / 2;
            ve.push_back(i);
            i++;
        }
    }
    if(ve.empty()) ve.push_back(1);
    char c = 'a';
    for(int x : ve) {
        rep(i, 0, x) cout << c;
        c++;
    }
    cout << '\n';
}