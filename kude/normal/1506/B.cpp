#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
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
        string s;
        cin >> s;
        int first = 0, last = n - 1;
        while(s[first] == '.') first++;
        while(s[last] == '.') last--;
        if (first == last) {
            cout << 1 << '\n';
            continue;
        }
        int ans = 2;
        for(int i = first; i < last;) {
            int j = i + k;
            if (j >= last) break;
            while(s[j] == '.') j--;
            ans++;
            i = j;
        }
        cout << ans << '\n';
    }
}