
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5005, M = 1e9 + 7;
int n, m;
int s[N], pref[N][N], f[N], h[N], L[N], R[N], LR[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> f[i] >> h[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] = pref[i - 1][j];
        }
        pref[i][s[i]]++;
    }
    int best = -1;
    ll ways = 0;
    for(int i = 0; i <= n; i++) {
        fill(L, L + N, 0);
        fill(R, R + N, 0);
        fill(LR, LR + N, 0);
        bool flag = false;
        for(int j = 1; j <= m; j++) {
            int amtL = pref[i][f[j]];
            int amtR = pref[n][f[j]] - amtL;
            if(f[j] == s[i]) {
                if(h[j] == amtL) {
                    flag = true;
                    if(h[j] <= amtR) {
                        LR[f[j]]++;
                    }else {
                        L[f[j]]++;
                    }
                }else if(h[j] <= amtR) {
                    R[f[j]]++;
                }
            }else if(h[j] <= amtL) {
                if(h[j] <= amtR) {
                    LR[f[j]]++;
                }else {
                    L[f[j]]++;
                }
            }else if(h[j] <= amtR) {
                R[f[j]]++;
            }
        }
        if(i > 0 && !flag) continue;
        int numcows = 0;
        ll numways = 1;
        for(int j = 1; j <= n; j++) {
            int val = L[j] * R[j] + L[j] * LR[j] + LR[j] * R[j] + LR[j] * (LR[j] - 1);
            if(val == 0) {
                if(j == s[i]) {
                    val = L[j] + LR[j];
                }else {
                    val = L[j] + R[j] + 2 * LR[j];
                }
                if(val != 0) {
                    numways = (numways * val) % M;
                    numcows++;
                }
            }else {
                numcows += 2;
                numways = (numways * val) % M;
            }
        }
        if(numcows > best) {
            best = numcows;
            ways = numways;
        }else if(numcows == best) {
            ways = (ways + numways) % M;
        }
    }
    cout << best << " " << ways << endl;
}