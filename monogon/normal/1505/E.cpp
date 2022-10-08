
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) {
        cin >> s[i];
    }
    int cnt = 0;
    int x = 0, y = 0;
    cnt += (s[x][y] == '*');
    while(true) {
        bool flag = false;
        for(int sum = 1; sum <= 15 && !flag; sum++) {
            for(int i = 0; i <= sum && !flag; i++) {
                int j = sum - i;
                int xx = x + i, yy = y + j;
                if(xx < n && yy < m && s[xx][yy] == '*') {
                    flag = true;
                    x = xx;
                    y = yy;
                    cnt++;
                    break;
                }
            }
        }
        if(!flag) break;
    }
    cout << cnt << '\n';
}