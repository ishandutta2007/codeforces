
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// upper bound: 2n
// number of iterations to get all cards in hand
// n iterations to move 1 2 3 ... n onto pile
// condition:
// suffix of b starting at 1 is in order, and all other cards are ready to be inserted in time
// if this holds, we can do it in pos[1] time
// otherwise, find most recent time for each card that it will enter hand
// latest one determines answer

const int N = 2e5 + 5;
int n, a[N], b[N], pos[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    fill(pos, pos + N, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        pos[b[i]] = i;
    }
    bool flag = true;
    if(pos[1] == -1) flag = false;
    else {
        int x = n - pos[1];
        for(int i = 1; i <= x; i++) {
            if(pos[i] != pos[1] + i - 1) {
                flag = false;
                break;
            }
        }
        for(int i = x + 1; i <= n; i++) {
            if(pos[i] != -1 && pos[i] > i - x - 2) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << pos[1] << '\n';
            return 0;
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        if(pos[i] != -1) {
            mx = max(mx, pos[i] - i + 2);
        }
    }
    cout << n + mx << '\n';
}