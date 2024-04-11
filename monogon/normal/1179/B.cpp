
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int l = 1, r = n;
    vector<pii> ans;
    while(l < r) {
        rep(i, 1, m + 1) {
            ans.push_back({l, i});
            ans.push_back({r, m - i + 1});
        }
        l++;
        r--;
    }
    if(l == r) {
        int i = 1, j = m;
        int it = 0;
        while(i <= j) {
            if(it % 2 == 0) {
                ans.push_back({l, i});
                i++;
            }else {
                ans.push_back({l, j});
                j--;
            }
            it++;
        }
    }
    for(auto &pa : ans) {
        cout << pa.first << ' ' << pa.second << '\n';
    }
}