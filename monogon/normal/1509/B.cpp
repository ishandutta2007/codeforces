
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
        int n; string s;
        cin >> n >> s;
        int kuroni = 0, ari = 0, cnt = 0;
        for(char c : s) {
            if(c == 'T') {
                if(cnt < n / 3) {
                    kuroni++;
                    cnt++;
                }else {
                    ari--;
                }
            }else {
                kuroni--;
                ari++;
            }
            if(kuroni < 0 || ari < 0) {
                cout << "NO\n";
                goto sleep;
            }
        }
        cout << "YES\n";
        sleep:;
    }
}