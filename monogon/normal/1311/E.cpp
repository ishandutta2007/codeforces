
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5005;
int lower[N], upper[N];
int t, n, d;

void solve(int n, int d, int r, int p) {
    if(n == 0) return;
    if(p != 1) cout << r << " ";
    for(int m = 0; m <= (n - 1) / 2; m++) {
        int m2 = n - m - 1;
        int L1 = lower[m], R1 = upper[m], L2 = -upper[m2] + d - n + 1, R2 = -lower[m2] + d - n + 1;
        if(L1 <= L2 && R1 >= L2) {
            // cout << "split " << m << " " << m2 << endl;
            int d1 = L2, d2 = d - d1 - n + 1;
            solve(m, d1, p, p + 1);
            solve(m2, d2, p, p + m + 1);
            return;
        }else if(L2 <= L1 && R2 >= L1) {
            int d1 = L1, d2 = d - d1 - n + 1;
            solve(m, d1, p, p + 1);
            solve(m2, d2, p, p + m + 1);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 1; i <= N; i++) {
        upper[i] = i * (i - 1) / 2;
        lower[i] = lower[i - 1] + floor(log2(i));
    }
    cin >> t;
    while(t--) {
        cin >> n >> d;
        if(d >= lower[n] && d <= upper[n]) {
            cout << "YES\n";
            solve(n, d, 0, 1);
            cout << endl;
        }else {
            cout << "NO\n";
        }
    }
}