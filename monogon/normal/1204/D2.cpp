
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

const int N = 1e5 + 5;
string s;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    reverse(all(s));
    int cnt = 0;
    int i = 0;
    while(i < n) {
        while(i < n && s[i] == '0') {
            i++;
            cnt++;
        }
        if(i == n) break;
        int j = i;
        while(j < n && s[j] == '1') {
            j++;
        }
        int amt = min(j - i, cnt);
        rep(k, i + amt, j) s[k] = '0';
        cnt -= j - i;
        cnt = max(cnt, 0);
        i = j;
    }
    reverse(all(s));
    cout << s << '\n';
}