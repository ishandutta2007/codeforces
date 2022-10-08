
#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

int n, x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        cin >> n >> x >> y;
        // dif is a divisor of y - x between 1 and n-1
        vi ans;
        int best = INT_MAX;
        rep(d, 1, n) {
            if((y - x) % d != 0) continue;
            int dif = (y - x) / d;
            int j = 0;
            while(j + 1 + d < n && x - (j + 1) * dif > 0) j++;
            vi arr;
            rep(i, 0, n) {
                arr.push_back(x - j * dif + i * dif);
            }
            if(arr.back() < best) {
                best = arr.back();
                ans.swap(arr);
            }
        }
        for(int x : ans) cout << x << ' ';
        cout << '\n';
    }
}