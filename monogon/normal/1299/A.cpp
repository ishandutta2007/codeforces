
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n;
int a[N], cnt[31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j <= 30; j++) {
            cnt[j] += ((a[i] >> j) & 1);
        }
    }
    int besti = 0, bestcnt = -1;
    for(int i = 0; i < n; i++) {
        int bits = 0;
        for(int j = 0; j <= 30; j++) {
            if(((a[i] >> j) & 1) && cnt[j] == 1) {
                bits += (1 << j);
            }
        }
        if(bits > bestcnt) {
            bestcnt = bits;
            besti = i;
        }
    }
    cout << a[besti];
    for(int i = 0; i < besti; i++) {
        cout << " " << a[i];
    }
    for(int i = besti + 1; i < n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
}