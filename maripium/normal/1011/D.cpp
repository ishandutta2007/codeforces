#include <bits/stdc++.h>
using namespace std;

int m, n, tt;
vector<int> p;

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cout << 1 << endl << flush;
        cin >> tt;
        if (tt == 0 || tt == -2) exit(0);
        if (tt == -1) p.push_back(0);
        else p.push_back(1);
    }
    
    int l = 2,r = m,ptr = 0;
    while (tt != 0 && tt != -2) {
        int mid = (l + r) >> 1;
        cout << mid << endl << flush;
        cin >> tt;
        if (p[ptr] == 0) tt = -tt;
        if (tt == 0 || tt == -2) exit(0);
        ptr = (ptr + 1) % n;
        if (tt == -1) r = mid - 1;
        else l = mid + 1;
    }
    exit(0);
}