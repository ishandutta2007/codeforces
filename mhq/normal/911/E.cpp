#include <bits/stdc++.h>
using namespace std;
int n, k;
const int maxN = 2 * (int)1e5 +  10;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    int cur = 1;
    stack < int > t;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        int x;
        x = a[i];
        //cout << x << endl;
        while (!t.empty() && t.top() < x) {
            if (t.top() != cur) {
                cout << -1;
                return 0;
            }
            else {
                t.pop();
                cur++;
            }
        }
        t.push(x);
    }
    for (int i = 1; i <= k; i++) cout << a[i] << " ";
    while (!t.empty()) {
        for (int i = t.top() - 1; i >= cur; i--) {
            cout << i << " ";
        }
        cur = t.top() + 1;
        t.pop();
    }
    for (int i = n; i >= cur; i--) {
        cout << i << " ";
    }
}