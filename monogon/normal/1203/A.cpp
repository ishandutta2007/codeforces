
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 205;
int q, n;
int p[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n >> p[0];
        if(n == 1) {
            cout << "YES" << endl;
            continue;
        }
        p[0]--;
        bool b1 = true;
        bool b2 = true;
        for(int i = 1; i < n; i++) {
            cin >> p[i];
            p[i]--;
            b1 = b1 && p[i] == (p[i - 1] + 1) % n;
            b2 = b2 && p[i] == (p[i - 1] + n - 1) % n;
        }
        b1 = b1 && p[0] == (p[n - 1] + 1) % n;
        b2 = b2 && p[0] == (p[n - 1] + n - 1) % n;
        cout << (b1 || b2 ? "YES" : "NO") << endl;
    }
}