
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
        cin >> n;
        string s;
        if(n == 1) {
            s = "a";
        }else if(n % 2 == 0) {
            // a^i b a^(i+1)
            // 2i + 2 = n
            // i = (n-2) / 2
            int i = (n-2) / 2;
            rep(j, 0, i) s.push_back('a');
            s.push_back('b');
            rep(j, 0, i + 1) s.push_back('a');
        }else {
            // a^i b c a^(i+1)
            // 2i + 3 = n
            // (n-3) / 2
            int i = (n - 3) / 2;
            rep(j, 0, i) s.push_back('a');
            s.push_back('b');
            s.push_back('c');
            rep(j, 0, i + 1) s.push_back('a');
        }
        cout << s << '\n';
    }
}