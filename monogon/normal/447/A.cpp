
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

const int N = 305;
int p, n, x;
bool b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> p >> n;
    rep(i, 1, n + 1) {
        cin >> x;
        x %= p;
        if(b[x]) {
            cout << i << '\n';
            return 0;
        }
        b[x] = true;
    }
    cout << "-1\n";
}