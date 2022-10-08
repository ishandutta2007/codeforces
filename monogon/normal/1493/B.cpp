
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

int rev[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

void solve() {
    int h, m;
    cin >> h >> m;
    string s;
    cin >> s;
    int H = (s[0] - '0') * 10 + s[1] - '0';
    int M = (s[3] - '0') * 10 + s[4] - '0';
    while(true) {
        if(rev[H % 10] != -1 && rev[H / 10] != -1 && rev[M % 10] != -1 && rev[M / 10] != -1) {
            int H2 = rev[M % 10] * 10 + rev[M / 10];
            int M2 = rev[H % 10] * 10 + rev[H / 10];
            if(H2 < h && M2 < m) {
                cout << H / 10 << H % 10 << ":" << M / 10 << M % 10 << "\n";
                return;
            }
        }
        M++;
        if(M >= m) {
            M = 0;
            H++;
            if(H >= h) {
                H = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}