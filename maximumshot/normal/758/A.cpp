#include <bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;
    int mx = 0;
    int sum = 0;
    for(int x, i = 0;i < n;i++) {
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }
    cout << n * mx - sum << "\n";
    return 0;
}