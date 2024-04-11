#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

typedef long long ll;

const int MAXN = 200100;

int n, a[MAXN], bit[2][MAXN];

void update(int c, int i, int v) {
    for (i++; i<MAXN; i+=i&-i) bit[c][i] += v;
}

int query(int c, int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[c][i];
    return ret;
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int nb = 0;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        update(a[i], i, 1);
        if (!a[i]) nb ++;
    }

    ll sum = 0;
    for (int i=0; i<n; i++) {
        if (!a[i]) sum += query(1, i);
        else sum += nb - query(0, i);
    }

    cout << sum / 2 << '\n';
    return 0;
}