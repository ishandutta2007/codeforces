
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

map<char, char> ma = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};

int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        string s;
        map<char, int> cnt; 
        cin >> s;
        for(char c : s) cnt[c]++;
        char c = 'R';
        if(cnt['S'] > cnt[c]) c = 'S';
        if(cnt['P'] > cnt[c]) c = 'P';
        int n = s.length();
        rep(i, 0, n) {
            cout << ma[c];
        }
        cout << '\n';
    }
}