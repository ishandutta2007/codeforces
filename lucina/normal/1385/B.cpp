#include<bits/stdc++.h>
using namespace std;
int n;
int a[256];
bool vis[256];

void solve () {
    cin >> n;
    int top = 0;
    for (int i = 1 ; i <= n + n ; ++ i) {
        int x;
        cin >> x;
        if (!vis[x]) {
            vis[x] = true;
            a[++ top] = x;
        }
    }
    assert(top == n);
    for (int i = 1 ; i <= n; ++ i)
        vis[i] = false, cout << a[i] << ' ';
    cout << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t -- ) {
            solve();
    }

}