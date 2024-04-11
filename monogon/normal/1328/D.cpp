
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int q, n, a[N];

// all same animal => color all 1
// n even => color alternating
// n odd & adjacent pair => color alternating and flip on the first adjacent
// otherwise => forced to use 3. color first 3 and alternate the rest.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool allsame = true;
        int adj = -1;
        for(int i = 0; i < n; i++) {
            if(a[i] != a[0]) allsame = false;
            if(a[i] == a[(i + 1) % n]) adj = n - i - 1;
        }
        if(allsame) {
            cout << "1\n";
            while(n--) cout << "1 ";
        }else if(n % 2 == 0) {
            cout << "2\n";
            while(n--) cout << (1 + n%2) << " ";
        }else if(adj != -1) {
            cout << "2\n";
            while(n--) cout << 1 + ((n < adj) ^ (n % 2)) << " ";
        }else {
            cout << "3\n";
            while(n--) cout << (n == 0 ? 3 : (1 + n%2)) << " ";
        }
        cout << "\n";
    }
}