#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10005;

int n, k, best=(int)(-1e9);
int f[MAXN], t[MAXN];

int joy(int a, int b) {
    if (b>k) return a-(b-k);
    return a;
}

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> f[i] >> t[i];
    for (int i=0; i<n; i++) best=max(best, joy(f[i], t[i]));
    cout << best << endl;
}