#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    bool turn = false;
    bool down = true;
    int curdig = 9;
    for (int i = 0; i < n; i++) {
        cout << curdig;
        if ((!turn) && curdig==8 && down) {
            turn=true;
            curdig=9;
            down=false;
        }
        else if (down) curdig = (curdig-1)%10;
        else curdig = (curdig+1) % 10;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        solve(n);
    }
}