
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
    string s;
    cin >> s;
    int n = s.length();
    int i = 0;
    string ans;
    while(i < n) {
        if(s[i] == '.') ans.push_back('0');
        else {
            if(s[i + 1] == '.') ans.push_back('1');
            else ans.push_back('2');
            i++;
        }
        i++;
    }
    cout << ans << '\n';
}