
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
ll b[N];
map<ll, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int maxcount = 0;
    ll c = -1;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        ll bit = b[i] & (-b[i]);
        cnt[bit]++;
        if(cnt[bit] > maxcount) {
            maxcount = cnt[bit];
            c = bit;
        }
    }
    cout << (n - maxcount) << endl;
    for(int i = 0; i < n; i++) {
        ll bit = b[i] & (-b[i]);
        if(bit != c) {
            cout << b[i] << endl;
        }
    }
}