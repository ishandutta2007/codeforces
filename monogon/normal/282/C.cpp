
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
    string a, b;
    cin >> a >> b;
    if(a.length() != b.length()) {
        cout << "NO\n";
        return 0;
    }
    bool flag = false, flag2 = false;
    for(char c : a) {
        if(c == '1') flag = true;
    }
    for(char c : b) {
        if(c == '1') flag2 = true;
    }
    cout << (flag == flag2 ? "YES" : "NO") << '\n';
}