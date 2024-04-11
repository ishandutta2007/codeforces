
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int i = 0;
    set<ll> se;
    se.insert(0);
    ll sum = 0;
    for(int j = 1; j <= n; j++) {
        while(se.count(a[j])) {
            se.erase(a[i]);
            i++;
        }
        sum += j - i;
        se.insert(a[j]);
    }
    cout << sum << '\n';
}