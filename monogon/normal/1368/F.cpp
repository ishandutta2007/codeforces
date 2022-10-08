
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

const int N = 1005;
int n, k;
bool lit[N];
int cnt = 0;

void ask(vi &ve) {
    int k = sz(ve);
    cout << sz(ve) << ' ';
    for(int x : ve) {
        cnt += !lit[x];
        lit[x] = true;
        cout << x + 1 << ' ';
    }
    cout << endl;
    int x;
    cin >> x;
    if(x == -1) exit(0);
    x--;
    rep(i, 0, k) {
        cnt -= lit[(x + i) % n];
        lit[(x + i) % n] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if(n <= 3) {
        cout << 0 << endl;
        return 0;
    }
    int best = 0;
    rep(i, 2, n + 1) {
        int amt = n - (n + i - 1) / i - i + 1;
        if(amt > best) {
            best = amt;
            k = i;
        }
    }
    while(cnt < best) {
        vi ve;
        rep(i, 0, n) {
            if(sz(ve) < k && i % k != 0 && !lit[i]) {
                ve.push_back(i);
            }
        }
        ask(ve);
    }
    cout << 0 << endl;
}