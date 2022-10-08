
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 4e5 + 5;
int t, n, g, s, b;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        g = s = b = n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i > 0 && a[i] != a[i - 1] && i < g) {
                g = i;
            }
        }
        for(int i = g; i < n; i++) {
            if(i - g > g && a[i] != a[i - 1]) {
                s = i - g;
                break;
            }
        }
        for(int i = g + s; i <= n / 2; i++) {
            if(i - (g + s) > g && a[i] != a[i - 1]) {
                b = i - (g + s);
            }
        }
        if(2 * (g + s + b) <= n) {
            cout << g << " " << s << " " << b << endl;
        }else {
            cout << "0 0 0" << endl;
        }
    }
}