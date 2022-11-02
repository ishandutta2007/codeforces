#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 1000100;
const int MAXX = 10000100;

int n, m, freq[MAXX], num[MAXX], pre[MAXX];
bool prime[MAXX];

void init() {
    for (int i=2; i<MAXX; i++) prime[i] = 1;

    for (int i=2; i<MAXX; i++) {
        if (prime[i]) {
            num[i] += freq[i];
            for (int j=i+i; j<MAXX; j+=i) {
                prime[j] = 0;
                num[i] += freq[j];
            }
        }
    }

    for (int i=2; i<MAXX; i++)
        pre[i] = pre[i-1] + num[i];
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        freq[x] ++;
    }

    init();

    cin >> m;
    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        if (l > MAXX-10) {
            cout << 0 << '\n';
            continue;
        }

        r = min(r, MAXX-5);

        cout << pre[r] - pre[l-1] << '\n';
    }

    return 0;
}