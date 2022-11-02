#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 100100;

int n, m;
int x[MAXN], l[MAXN], c[MAXN];
ll len[MAXN];

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    memset(x, -1, sizeof(x));

    cin >> m;
    for (int i=0; i<m; i++) {
        int qtype; cin >> qtype;
        if (qtype == 1) {
            cin >> x[i];
            len[i+1] = len[i] + 1;
        } else {
            cin >> l[i] >> c[i];
            len[i+1] = len[i] + l[i] * c[i];
        }
    }

    cin >> n;
    for (int i=0; i<n; i++) {
        ll num; cin >> num;
        while (1) {
            int ind = lower_bound(len, len + m + 1, num) - len;
            if (num == len[ind] && x[ind-1] != -1) {
                cout << x[ind-1] << ' ';
                break;
            }

            num -= len[ind-1];
            num %= l[ind-1];

            if (num == 0) num = l[ind-1];
        }
    }

    return 0;
}