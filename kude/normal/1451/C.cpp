#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        int ca[26] = {}, cb[26] = {};
        for(char t: a) {
            ca[t-'a']++;
        }
        for(char t: b) {
            cb[t-'a']++;
        }
        rep(i, 26) {
            while(ca[i] > cb[i]) {
                ca[i] -= k;
                ca[i+1] += k;
            }
        }
        bool ok = true;
        rep(i, 26) if (ca[i] != cb[i]) {
            ok = false;
            break;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}