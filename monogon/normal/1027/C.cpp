
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// minimize P^2 / S
// choose two lengths. Must have two sticks of each length
// (note: square requires four sticks of the one length)
// lengths A and B
// P = (2A + 2B), S = AB
// (2A + 2B)^2 / AB = 4 (A^2 + B^2 + 2AB) / AB
// 4(A^2 + B^2) / AB + 2
// minimize A/B + B/A = A/B + 1 / (A/B)
// x + 1/x, only increases as x increases
// minimize A/B, so choose consecutive lengths
// try to choose square if possible

// why am I so bad

const int N = 1e6 + 5;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        long double best = DBL_MAX;
        int idx = 0, idx2 = 0;
        int j = -1;
        for(int i = 0; i + 2 <= n; i++) {
            if(a[i] == a[i + 1]) {
                if(j != -1) {
                    if(i - j >= 2) {
                        long double P = (2 * a[i] + 2 * a[j]);
                        if(((P * P) / a[i]) / a[j] < best) {
                            best = ((P * P) / a[i]) / a[j];
                            idx = j;
                            idx2 = i;
                        }
                    }
                    if(a[i] != a[j]) j = i;
                }else {
                    j = i;
                }
            }
        }
        cout << a[idx] << " " << a[idx] << " " << a[idx2] << " " << a[idx2] << "\n";
    }
}