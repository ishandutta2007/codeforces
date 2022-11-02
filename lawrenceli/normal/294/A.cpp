#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i=0, _##i=(n); i<_##i; i++)

const int MAXN = 105;

int n, m;
int a[MAXN];

int main() {
    cin >> n;
    rep(i, n) cin >> a[i+1];
    cin >> m;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        a[x-1]+=y-1;
        a[x+1]+=a[x]-y;
        a[x]=0;
    }
    rep(i, n) cout << a[i+1] << endl;
}