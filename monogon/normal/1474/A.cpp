
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
    int te;
    cin >> te;
    while(te--) {
        int n;
        string s;
        cin >> n >> s;
        string ans;
        int prval = -1;
        rep(i, 0, n) {
            int val = s[i] - '0';
            if(val + 1 != prval) {
                ans.push_back('1');
                prval = val + 1;
            }else {
                ans.push_back('0');
                prval = val;
            }
        }
        cout << ans << '\n';
    }
}