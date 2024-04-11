
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

int t;
ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        int p2 = 0, p3 = 0;
        while(n % 2 == 0) {
            n /= 2;
            p2++;
        }
        while(n % 3 == 0) {
            n /= 3;
            p3++;
        }
        if(n != 1 || p2 > p3) {
            cout << "-1\n";
            continue;
        }
        cout << p2 + 2 * (p3 - p2) << '\n';
    }
}