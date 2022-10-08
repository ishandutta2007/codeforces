
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

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    vector<string> names;
    for(char c = 'a'; c <= 'z'; c++) {
        names.push_back(string(1, c + 'A' - 'a'));
    }
    for(char c = 'A'; c <= 'Z'; c++) {
        names.push_back(string(1, c) + string(1, c - ('A' - 'a')));
    }
    vector<int> ve(n);
    rep(i, 0, k - 1) {
        ve[i] = i;
    }
    rep(i, k - 1, n) {
        string str;
        cin >> str;
        if(str == "NO") {
            ve[i] = ve[i - k + 1];
        }else {
            ve[i] = i;
        }
    }
    for(int x : ve) {
        cout << names[x] << ' ';
    }
    cout << endl;
}