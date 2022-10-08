
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int LG = 61;
int q, t;
ll shift[LG];
ll x, k;

ll mod(ll a, ll b) {
    return ((a % b) + b) % b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> t >> x;
        int l = log2(x);
        if(t == 1) {
            cin >> k;
            shift[l] = mod(shift[l] + k, 1LL << l);
        }else if(t == 2) {
            cin >> k;
            k %= (1LL << l);
            for(int i = l; i < LG; i++) {
                shift[i] = mod(shift[i] + k * (1LL << (i - l)), 1LL << i);
            }
        }else {
            x = ((1LL << l) + mod(x - (1LL << l) + shift[l], (1LL << l)));
            while(x > 0) {
                cout << ((1LL << l) + mod(x - (1LL << l) - shift[l], (1LL << l))) << " ";
                x /= 2;
                l--;
            }
            cout << '\n';
        }
    }
}