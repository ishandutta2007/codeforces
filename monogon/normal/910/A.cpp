
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    int n, d;
    string s;
    cin >> n >> d >> s;
    int pos = 0, moves = 0;
    while(pos < n - 1) {
        int idx = min(n - 1, pos + d);
        while(idx > pos && s[idx] == '0') idx--;
        if(idx == pos) {
            cout << -1 << '\n';
            return 0;
        }
        pos = idx;
        moves++;
    }
    cout << moves << '\n';
}