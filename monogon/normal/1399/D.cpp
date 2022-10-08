
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
        int cnt = 0;
        vi v(n);
        queue<int> s0, s1;
        int k = 1;
        rep(i, 0, n) {
            if(s[i] == '0') {
                if(s1.empty()) {
                    s0.push(k);
                    v[i] = k;
                    k++;
                }else {
                    v[i] = s1.front(); s1.pop();
                    s0.push(v[i]);
                }
            }else {
                if(s0.empty()) {
                    s1.push(k);
                    v[i] = k;
                    k++;
                }else {
                    v[i] = s0.front(); s0.pop();
                    s1.push(v[i]);
                }
            }
        }
        cout << k - 1 << '\n';
        rep(i, 0, n) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
}