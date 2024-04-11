
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, x0, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x0;
    int A = -1, B = 1005;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if(a > b) swap(a, b);
        A = max(A, a);
        B = min(B, b);
    }
    if(A > B) {
        cout << -1 << endl;
    }else if(x0 > B) {
        cout << x0 - B << endl;
    }else if(x0 < A) {
        cout << A - x0 << endl;
    }else {
        cout << 0 << endl;
    }
}