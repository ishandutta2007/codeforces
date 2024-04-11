
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5005;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) {
            for(int j = i + 2; j < n; j++) {
                if(a[i] == a[j]) {
                    cout << "YES" << endl;
                    goto endloop;
                }
            }
        }
        cout << "NO" << endl;
        endloop:;
    }
}