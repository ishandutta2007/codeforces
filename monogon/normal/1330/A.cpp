
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        unique(a, a + n);
        int i = 0, j = 0;
        while(true) {
            if(i < n && a[i] == j + 1) {
                i++, j++;
            }else if(x > 0) {
                x--; j++;
            }else break;
        }
        cout << j << endl;
    }
}