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
    VI a; a.reserve(1000);
    for(int i = 1; a.size() < 1000; i++) {
        if (i % 3 == 0 || to_string(i).back() == '3') continue;
        a.push_back(i);
    }
    int tt;
    cin >> tt;
    while(tt--) {
        int k;
        cin >> k;
        cout << a[k - 1] << '\n';
    }
}