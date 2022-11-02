#include <bits/stdc++.h>

using namespace std;

const int MAXN = 600000;

int CNT = 0;

const double pi = 3.141592653589793;
const double eps = 1e-9;

void solve() {
    int n;
    int s = 0, mx = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        mx = max(mx, a);
        s+=a;
    }
    cout << mx * n - s;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/home/step/CLionProjects/codeforces/input", "r", stdin);
    freopen("/home/step/CLionProjects/codeforces/output", "w", stdout);
#endif
    solve();
    return 0;
}