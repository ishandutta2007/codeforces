
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
ll a[N];
ll inc[N], inc2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = 1e9 + 5;
    a[n + 1] = 0;
    inc[0] = 1;
    inc2[n + 1] = 1;
    ll m = 1;
    for(int i = 1; i <= n + 1; i++) {
        if(a[i - 1] < a[i]) inc[i] = inc[i - 1] + 1;
        else inc[i] = 1;
        m = max(m, inc[i]);
    }
    for(int i = n; i >= 0; i--) {
        if(a[i] < a[i + 1]) inc2[i] = inc2[i + 1] + 1;
        else inc2[i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        if(a[i - 1] < a[i + 1]) {
            m = max(m, inc[i - 1] + inc2[i + 1]);
        }
    }
    cout << m << endl;
}