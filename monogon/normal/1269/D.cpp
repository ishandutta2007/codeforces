
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5;
int n;
ll a[N];
ll b[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i];
        if(a[i] % 2 == 1) {
            b[i % 2]++;
        }
    }
    cnt -= abs(b[0] - b[1]);
    cout << cnt / 2 << endl;
}