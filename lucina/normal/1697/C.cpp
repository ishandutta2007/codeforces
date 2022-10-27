#include<bits/stdc++.h>
using namespace std;
const int nax = 4e5 + 10;
int n;
string s, t;

bool solve() {
    cin >> n >> s >> t;
    if (count(s.begin(), s.end(), 'b') != count(t.begin(), t.end(), 'b')) return false;
    string xs, xt;
    vector <int> a, b;
    
    for (int i = 0 ; i < n ; ++ i) {
        if (s[i] != 'b') {
            xs += s[i];
            a.push_back(i);
        }
        if (t[i] != 'b') {
            xt += t[i];
            b.push_back(i);
        }
    }
    if (xs != xt) return false;
    
    for (int i = 0 ; i < a.size() ; ++ i) {
        if (xs[i] == 'a' && a[i] > b[i]) return false;
        if (xs[i] == 'c' && a[i] < b[i]) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    
    for (cin >> T ; T -- ; ) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
    
}