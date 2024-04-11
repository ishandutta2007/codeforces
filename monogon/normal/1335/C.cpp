
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        map<int, int> cnt;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int a = cnt.size();
        int b = 0;
        for(auto p : cnt) {
            b = max(b, p.second);
        }
        if(a == b) {
            cout << a - 1 << '\n';
        }else {
            cout << min(a, b) << '\n';
        }
    }
}