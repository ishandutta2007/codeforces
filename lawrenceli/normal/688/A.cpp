#include <bits/stdc++.h>

using namespace std;

int n, d;

int main() {
    cin >> n >> d;
    int ma = 0, cur = 0;
    for (int i = 0; i < d; i++) {
        string s; cin >> s;
        bool b = 0;
        for (int j = 0; j < n; j++)
            if (s[j] == '0') b = 1;
        if (b) cur++;
        else ma = max(ma, cur), cur = 0;
    }
    
    cout << max(ma, cur) << '\n';
}