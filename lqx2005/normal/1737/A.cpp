#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pr pair<int, int>
using namespace std;
void rmain() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(26);
    FOR(i, 1, n) {
        char x;
        cin >> x;
        cnt[x - 'a']++;
    }
    FOR(i, 1, k) {
        int z = 0;
        FOR(j, 0, 25) {
            if(z >= n / k) break;
            if(cnt[j] > 0) {
                cnt[j]--;
                z++;
            } else break;
        }
        cout << (char)('a' + z);
    }
    cout << "\n";
}
int main() {
    int t;
    for(cin >> t; t--; ) rmain();
    return 0;
}