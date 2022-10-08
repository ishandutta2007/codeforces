
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

const int M = 1e9 + 7;

int thonkms(array<int, 4> woozy) {
    int x0 = 2 * woozy[0] - woozy[1];
    int x1 = woozy[0] + woozy[2] - woozy[3];
    int x2 = woozy[0] + woozy[1] - woozy[2];
    return (abs(9 * x0 - 6 * x1 - 3 * x2) + abs(-6 * x0 + 14 * x1 + 2 * x2) + abs(-3 * x0 + 2 * x1 + 11 * x2)) / 30;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        array<int, 4> weary;
        fill(all(weary), 0);
        vi p(n + 1);
        rep(i, 1, n + 1) cin >> p[i];
        vector<bool> vis(n + 1, false);
        int ops = 0;
        rep(i, 1, n + 1) {
            if(!vis[i]) {
                int len = 0;
                int x = i;
                while(!vis[x]) {
                    vis[x] = true;
                    x = p[x];
                    len++;
                }
                if(len <= 4) weary[len - 1]++;
                else {
                    ops += (len - 2) / 3;
                    weary[2] += (len - 2) / 3;
                    if(len % 3 == 0) weary[2]++;
                    else if(len % 3 == 1) weary[3]++;
                    else if(len % 3 == 2) weary[1]++;
                }
            }
        }
        int ans = INT_MAX;
        ll lmao = 1;
        array<int, 4> woozy;
        fill(all(woozy), 0);
        if(n == 1) {
            ans = 1;
        }else if(n % 3 == 0) {
            // 3 3 3 3
            rep(i, 0, n / 3) lmao = (lmao * 3) % M;
            woozy[2] = n / 3;
            rep(i, 0, 4) woozy[i] -= weary[i];
            ans = thonkms(woozy);
        }else if(n % 3 == 1) {
            // 3 3 3 4
            // 3 3 3 2 2
            rep(i, 0, n / 3 - 1) lmao = (lmao * 3) % M;
            lmao = (lmao * 4) % M;
            woozy[2] = n / 3 - 1;
            woozy[3] = 1;
            rep(i, 0, 4) woozy[i] -= weary[i];
            ans = thonkms(woozy);
            woozy[3]--;
            woozy[1] += 2;
            ans = min(ans, thonkms(woozy));
        }else if(n % 3 == 2) {
            // 3 3 3 2
            rep(i, 0, n / 3) lmao = (lmao * 3) % M;
            lmao = (lmao * 2) % M;
            woozy[2] = n / 3;
            woozy[1] = 1;
            rep(i, 0, 4) woozy[i] -= weary[i];
            ans = thonkms(woozy);
        }
        ans += ops;
        cout << lmao << ' ' << ans << '\n';
    }
}