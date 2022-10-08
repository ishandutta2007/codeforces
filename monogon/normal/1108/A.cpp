
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
ll l, r, L, R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> l >> r >> L >> R;
        for(int x : {l, r}) {
            for(int y : {L, R}) {
                if(x != y) {
                    cout << x << " " << y << endl;
                    goto endloop;
                }
            }
        }
        endloop:;
    }
}