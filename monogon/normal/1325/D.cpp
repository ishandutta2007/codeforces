
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll u, v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> u >> v;
    if(u > v || (v - u) % 2 == 1) {
        cout << -1 << endl;
    }else if(u == 0 && v == 0) {
        cout << 0 << endl;
    }else if(u == v) {
        cout << 1 << endl << u << endl;
    }else if((((v - u) / 2) & u) == 0) {
        cout << 2 << endl << ((v + u) / 2) << " " << ((v - u) / 2) << endl;
    }else {
        cout << 3 << endl << u << " " << ((v - u) / 2) << " " << ((v - u) / 2) << endl;
    }
}