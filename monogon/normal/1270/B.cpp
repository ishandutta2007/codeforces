
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n, k;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        int j = -1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i > 0 && abs(a[i] - a[i - 1]) >= 2) j = i - 1;
        }
        if(j >= 0) {
            cout << "YES" << endl << (j + 1) << " " << (j + 2) << endl;
        }else cout << "NO" << endl;
    }
}