#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
using namespace std;
int n;
int a[100005];
void rmain() {
    cin >> n;
    int o = 0;
    FOR(i, 1, n) cin >> a[i];
    int l = 1, r = n;
    int cnt = 0;
    while(l <= r) {
        while(l <= n && a[l] == 0) l++;
        while(r >= 1 && a[r] == 1) r--;
        if(l > r) break;
        cnt++;
        l++, r--;
    }
    cout << cnt << "\n";
    return;
}
int main() {
    int T;
    for(cin >> T; T--; ) rmain();
}