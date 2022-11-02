#include <bits/stdc++.h>

using namespace std;

int k, n[4];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> k;
    int cnt = 0, b = 0;
    while (k>0) {
        n[cnt]++;
        if (cnt == 1) {
            if (!b) cnt = 2, b = 1;
            else cnt = 3;
        } else cnt = (cnt+1)%4;
        k--;
    }

    cout << '+'; for (int i=0; i<24; i++) cout << '-'; cout << "+\n";
    for (int i=0; i<4; i++) {
        cout << '|';
        for (int j=0; j<11; j++) {
            if (j<n[i]) cout << 'O';
            else if (i != 2 || j == 0) cout << '#';
            else cout << '.';
            cout << '.';
        }
        if (i != 2) cout << '|';
        else cout << '.';
        if (i == 0) cout << 'D';
        else cout << '.';
        cout << '|';
        if (i == 0 || i == 3) cout << ')';
        cout << '\n';
    }
    cout << '+'; for (int i=0; i<24; i++) cout << '-'; cout << "+\n";
    return 0;
}