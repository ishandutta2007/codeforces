#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;

typedef double db;
typedef long long i64;
const int N = 2e5 + 10;
int n, p[N], vis[N], a[N], b[N];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        p[a[i]] = b[i], p[b[i]] = a[i];
    }
    n <<= 1;
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        int x = i;
        while(!vis[x]) {
            vis[x] = 1, vis[p[x]] = 2;
            x = p[x] ^ 1;
        }
    }
    n >>= 1;
    for(int i = 0; i < n; i++) {
        cout << vis[a[i]] <<" " << vis[b[i]] << endl;
    }
    return 0;
}