
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1e5 + 5;
int n;
ll a[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    if(a[n - 1] >= a[n - 2] + a[n - 3]) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << a[n - 1] << " " << a[n - 2];
    for(int i = 0; i < n - 2; i++) {
        cout << " " << a[i];
    }
    cout << endl;
}