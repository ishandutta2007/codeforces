
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        reverse(a.begin(), a.end());
        for(int x : a) cout << x << ' ';
        cout << '\n';
    }
}