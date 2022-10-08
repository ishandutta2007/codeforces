
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int t, n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        int i = 0, j = n - 1;
        while(i < n && s[i] == '0') i++;
        while(j >= 0 && s[j] == '1') j--;
        if(i < j) {
            cout << s.substr(0, i) << 0 << s.substr(j + 1) << '\n';
        }else {
            cout << s << '\n';
        }
    }
}