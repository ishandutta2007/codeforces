
#include <bits/stdc++.h>

using namespace std;

// Solution 2 from editorial
// Fix the bits one-by-one in reverse order.
// Simulate the operations manually, achieving O(n^2) time complexity

int t, n;
string a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        vector<int> ops;
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] != b[i]) {
                if(a[0] == b[i]) {
                    ops.push_back(1);
                    a[0] = '0' + !(a[0] - '0');
                }
                reverse(a.begin(), a.begin() + i + 1);
                for(int j = 0; j <= i; j++) {
                    a[j] = '0' + !(a[j] - '0');
                }
                ops.push_back(i + 1);
            }
        }
        cout << ops.size() << ' ';
        for(int x : ops) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}