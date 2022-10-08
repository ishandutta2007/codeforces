
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
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        int cnt = 0;
        set<int> se;
        rep(i, 0, n) {
            int a;
            cin >> a;
            if(a == 1) {
                se.insert(i);
                cnt++;
            }
        }
        cout << *prev(se.end()) - *se.begin() + 1 - cnt << '\n';
    }
}