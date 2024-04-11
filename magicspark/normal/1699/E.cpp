#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int nmax = 5e6 + 5;
int appear[nmax];
int mxval[nmax];
int toggle[nmax];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
        int n, m, mn = nmax, mx = 0;
        cin >> n >> m;
        for (int i = 0; i <= m; ++i){
            appear[i] = toggle[i] = mxval[i] = 0;
        }
        for (int i = 0, x; i < n; i++){
            cin >> x;
            appear[x] = 1;
            toggle[x] = 1;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        for (int i = 0; i <= mx; i++){
            mxval[i] = i;
        }
        int ptr = mx, smax = mx - mn;
        for (int i = mx; i >= 1; i--){
            for (ll j = (ll)i * i; j <= mx; j += i){
                if (appear[j])
                    toggle[mxval[j]]--;
                mxval[j] = min(mxval[j], mxval[j / i]);
                if (appear[j])
                    toggle[mxval[j]]++;
            }
            while (toggle[ptr] == 0)
                ptr--;
            if (i <= mn)
                smax = min(smax, ptr - i);
        }
        cout << smax << '\n';
    }
}