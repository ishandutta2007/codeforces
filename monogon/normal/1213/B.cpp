
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 150005;
int n, t, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int m = a[n - 1];
        int bad = 0;
        for(int i = n - 2; i >= 0; i--) {
            bad += (a[i] > m);
            m = min(a[i], m);
        }
        cout << bad << endl;
    }
}