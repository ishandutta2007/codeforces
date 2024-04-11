#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
using namespace std;
const int N = 100 + 10;
int n;
void solve() {
    cin >> n;
    int c[2] = {0, 0};
    FOR(i, 1, n) {
        int x;
        cin >> x;
        c[x & 1] += 1;
    }
    c[0] &= 1;
    if(c[1] & 1) {
        c[1] /= 2;
        if(c[1] & 1) {
            cout << "Alice\n";
        } else {
            if(c[0]) cout << "Alice\n";
            else cout << "Bob\n";
        }
    } else {
        if(!c[1]) {
            cout << "Alice\n";
        } else {
            c[1] /= 2;
            if(c[1] & 1) {
                cout << "Bob\n";
            } else {
                cout << "Alice\n";
            }
        }
    }
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}