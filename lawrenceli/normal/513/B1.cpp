#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;

int n, m, p[MAXN];

struct data {
    int ar[MAXN];
    int v;
} dat[100000];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) p[i] = i+1;
    int cnt = 0, ma = 0;
    do {
        int sum = 0;
        for (int j=0; j<n; j++)
            for (int k=j; k<n; k++) {
                int mi = n;
                for (int l=j; l<=k; l++) mi = min(mi, p[l]);
                sum += mi;
            }
        for (int i=0; i<n; i++) dat[cnt].ar[i] = p[i];
        dat[cnt].v = sum;
        cnt++;
        ma = max(ma, sum);
    } while (next_permutation(p, p+n));

    for (int i=0; i<cnt; i++)
        if (dat[i].v == ma) {
            m--;
            if (m == 0) {
                for (int j=0; j<n; j++) cout << dat[i].ar[j] << ' ';
                return 0;
            }
        }
    return 0;
}