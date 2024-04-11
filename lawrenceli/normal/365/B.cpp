#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 100100;

int n, a[MAXN];
bool b[MAXN];

int main() {
    ios :: sync_with_stdio(false);
    
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=2; i<n; i++)
        b[i] = (a[i] == a[i-1] + a[i-2]);
    
    int rt = 0, ans = 0;
    for (int lt=0; lt<n; lt++) {
        rt = min(max(rt, lt + 2), n);
        while (rt < n && b[rt]) rt++;
        ans = max(ans, rt - lt);
    }
    
    cout << ans << endl;
    return 0;
}