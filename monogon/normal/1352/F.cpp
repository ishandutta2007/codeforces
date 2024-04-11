
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

// build string of length n[1]
// 1 0 1 0 1 0

const int N = 305;
int t, n[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n[0] >> n[1] >> n[2];
        int nn = n[0] + n[1] + n[2] + 1;
        string s;
        if(n[1] == 0) {
            assert(n[2] == 0 || n[0] == 0);
            if(n[0] != 0) {
                while(nn--) s.push_back('0');
            }else {
                while(nn--) s.push_back('1');
            }
        }else {
            s.push_back('0');
            while(n[0]--) {
                s.push_back('0');
            }
            s.push_back('1');
            while(n[2]--) {
                s.push_back('1');
            }
            n[1]--;
            rep(i, 0, n[1]) {
                s.push_back('0' + (i % 2));
            }
        }
        cout << s << '\n';
    }
}