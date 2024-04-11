
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
        ll a, b;
        cin >> a >> b;
        a = abs(b - a);
        cout << (a + 9) / 10 << '\n';
    }
}