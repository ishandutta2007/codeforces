
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 100005;
int t, n;
ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}