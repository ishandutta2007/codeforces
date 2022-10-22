#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
using namespace std;
int n;
int a[100005], b[100005];
void rmain() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i], b[a[i]] = i;
    FOR(i, 1, n) {
        if(b[i] < n) cout << b[i] + 1 <<" ";
        else cout << 1 << " "; 
    }
    cout << "\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    for(cin >> T; T--; ) rmain();
}