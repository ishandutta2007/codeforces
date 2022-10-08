
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    if(n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << 1;
    for(int i = 5; i < 2 * n; i += 4) {
        cout << " " << (i - 1) << " " << i;
    }
    for(int i = 3; i < 2 * n; i += 4) {
        cout << " " << (i - 1) << " " << i;
    }
    cout << " " << (2 * n) << endl;
}