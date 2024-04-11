
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
        vi a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        int mx = *max_element(all(a));
        int sum = accumulate(all(a), 0);
        if(mx > sum - mx) {
            cout << "T\n";
        }else if(sum % 2 == 1) {
            cout << "T\n";
        }else {
            cout << "HL\n";
        }
    }
}