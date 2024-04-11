
#include <bits/stdc++.h>
using namespace std;

// Solution 1 from editorial
// Credit: The testers Kuroni and SecondThread independently came up with this elegant solution,
//     while solution 2 from editorial was intended.
// We convert a -> 0000000 -> b
// to convert a string to 0000000, we make prefix 2 all same bit, then prefix 3 all same bit, etc.
// to convert 0000000 -> b, we convert b -> 0000000 and reverse the order of operations.

int t, n;
string a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        vector<int> ops1, ops2;
        a += '0'; b += '0';
        for(int i = 1; i <= n; i++) {
            if(a[i] != a[i - 1]) ops1.push_back(i);
            if(b[i] != b[i - 1]) ops2.push_back(i);
        }
        ops1.insert(ops1.end(), ops2.rbegin(), ops2.rend());
        cout << ops1.size();
        for(int x : ops1) {
            cout << ' ' << x;
        }
        cout << '\n';
    }
}