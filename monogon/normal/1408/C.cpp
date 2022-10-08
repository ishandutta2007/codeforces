
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
        ll l;
        cin >> n >> l;
        vector<ll> a(n);
        rep(i, 0, n) cin >> a[i];
        double car1 = 0, car2 = l;
        int j = 0, k = n - 1;
        double ans = 0;
        while(j <= k) {
            double t1 = (a[j] - car1) / (1 + j);
            double t2 = (car2 - a[k]) / (n - k);
            if(t1 < t2) {
                ans += t1;
                car1 = a[j];
                car2 -= t1 * (n - k);
                j++;
            }else {
                ans += t2;
                car2 = a[k];
                car1 += t2 * (j + 1);
                k--;
            }
        }
        ans += (car2 - car1) / (1 + j + n - k);
        cout << fixed << setprecision(8);
        cout << ans << '\n';
    }
}