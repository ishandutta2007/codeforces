
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1005;
int n;
ll m[N], a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll sum = a[i] = m[i];
        for(int j = i - 1; j >= 0; j--) {
            sum += (a[j] = min(m[j], a[j + 1]));
        }
        for(int j = i + 1; j < n; j++) {
            sum += (a[j] = min(m[j], a[j - 1]));
        }
        if(sum > ans) {
            ans = sum;
            for(int j = 0; j < n; j++) b[j] = a[j];
        }
    }
    for(int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
}