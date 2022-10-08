
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
        bool win = false;
        if(n % 2 == 0) {
            win = true;
            for(int i = 1; i < n; i += 2) {
                if((s[i] - '0') % 2 == 0) {
                    win = false;
                }
            }
        }else {
            for(int i = 0; i < n; i += 2) {
                if((s[i] - '0') % 2 == 1) {
                    win = true;
                }
            }
        }
        cout << (win ? 1 : 2) << '\n';
    }
}