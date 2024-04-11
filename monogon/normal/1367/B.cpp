
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

const int N = 45;
int t, n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        int e[2] = {0, 0};
        rep(i, 0, n) {
            cin >> a[i];
            if((a[i] % 2) != (i % 2)) {
                e[a[i] % 2]++;
            }
        }
        if(e[0] != e[1]) {
            cout << "-1\n";
        }else {
            cout << e[0] << '\n';
        }
    }
}