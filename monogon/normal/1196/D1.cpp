
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 2e5 + 5;
int q, n, k;
string s;
int c[MAX_N][3];
int sum[3];

// the key is that there are only 3 cyclic shifts
// of the infinite string to check

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        cin >> n >> k >> s;
        sum[0] = sum[1] = sum[2] = 0;
        for(int i = 0; i < n; i++) {
            int type = ((s[i] == 'R' ? 0 : s[i] == 'G' ? 2 : 1) + i) % 3;
            c[i][0] = type == 0;
            c[i][1] = type == 1;
            c[i][2] = type == 2;
            if(i < k) {
                sum[0] += c[i][0];
                sum[1] += c[i][1];
                sum[2] += c[i][2];
            }
        }
        int maxsum = 0;
        for(int i = 0; i + k <= n; i++) {
            maxsum = max(maxsum, max(sum[0], max(sum[1], sum[2])));
            if(i + k < n) {
                sum[0] += c[i + k][0] - c[i][0];
                sum[1] += c[i + k][1] - c[i][1];
                sum[2] += c[i + k][2] - c[i][2];
            }
        }
        cout << (k - maxsum) << endl;
    }
}