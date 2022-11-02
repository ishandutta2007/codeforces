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
    int games = n * (n-1) / 2;
    if (n%2 == 0) {
        for (int i = 1; i < n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (j==i+1 && i%2 != 0) cout << "0 ";
                else if ((i+j)%2==0) cout << "1 ";
                else cout << "-1 ";
            }
        }
        cout << '\n';
    } else {
        for (int i = 1; i < n; i++) {
            for (int j = i+1; j <= n; j++) {
                if ((i+j)%2==0) cout << "1 ";
                else cout << "-1 ";
            }
        }
        cout << '\n';
    }
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