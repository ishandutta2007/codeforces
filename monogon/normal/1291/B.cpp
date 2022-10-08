
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5;
int t, n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int i = 0, j = n - 1;
        while(i < n && a[i] >= i) i++;
        while(j >= 0 && a[j] >= n - j - 1) j--;
        cout << (i > j + 1 ? "Yes" : "No") << endl;
    }
}