#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int x[nax];
int y[nax];

void solve() {
    cin >> n;

    vector <int> pos, neg;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> x[i];
    }
    vector <int> a;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> y[i];
        y[i] -= x[i];
    }
    sort(y + 1, y + 1 + n);
    int tail = n, head = 1;
    int ans = 0;
    while (head < tail) {
        while (head < tail && y[tail] + y[head] < 0) head += 1;
        if (head < tail && y[tail] + y[head] >= 0) {
            ans += 1;
        } else break;
        head += 1;
        tail -= 1;
    }
    cout << ans << '\n';
}

int main() {

    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }

}