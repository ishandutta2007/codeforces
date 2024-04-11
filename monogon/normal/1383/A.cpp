
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

int n;
string s, t;
int dsu[20];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        cin >> n >> s >> t;
        fill(dsu, dsu + 20, -1);
        bool flag = false;
        rep(i, 0, n) {
            if(s[i] > t[i]) flag = true;
            join(s[i] - 'a', t[i] - 'a');
        }
        if(flag) {
            cout << "-1\n";
            continue;
        }
        int cnt = 0;
        rep(i, 0, 20) {
            if(dsu[i] < 0) cnt += -dsu[i] - 1;
        }
        cout << cnt << '\n';
    }
}