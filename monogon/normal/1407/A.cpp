
#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vi a(n);
        vi v0, v1;
        rep(i, 0, n) {
            cin >> a[i];
            if(a[i] == 0) v0.push_back(i);
            else v1.push_back(i);
        }
        if(2 * sz(v0) >= n) {
            cout << sz(v0) << '\n';
            for(int x : v0) cout << 0 << ' ';
            cout << '\n';
        }else {
            if(sz(v1) % 2 != 0) v1.pop_back();
            cout << sz(v1) << '\n';
            for(int x : v1) cout << 1 << ' ';
            cout << '\n';
        }
    }
}