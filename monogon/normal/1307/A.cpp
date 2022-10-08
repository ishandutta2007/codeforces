
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int t, n, d, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> d;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < a[i]; j++) {
                if(d >= i) {
                    d -= i;
                    a[0]++;
                }
            }
        }
        cout << a[0] << endl;
    }
}