
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
    if(s.length() == 1) {
        cout << 0 << '\n';
        return 0;
    }
    int sum = 0, cnt = 1;
    for(char c : s) {
        sum += c - '0';
    }
    while(sum >= 10) {
        cnt++;
        int x = sum;
        sum = 0;
        while(x > 0) {
            sum += x % 10;
            x /= 10;
        }
    }
    cout << cnt << '\n';
}