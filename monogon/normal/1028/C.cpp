
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

const int N = 2e5 + 5;
int xl[N], yl[N], xr[N], yr[N], prefxl[N], suffxl[N], prefyl[N], suffyl[N], prefxr[N], suffxr[N], prefyr[N], suffyr[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
    }
    prefxl[0] = suffxl[n + 1] = prefyl[0] = suffyl[n + 1] = -1e9 - 5;
    prefxr[0] = suffxr[n + 1] = prefyr[0] = suffyr[n + 1] = 1e9 + 5;
    rep(i, 1, n + 1) {
        prefxl[i] = max(prefxl[i - 1], xl[i]);
        prefyl[i] = max(prefyl[i - 1], yl[i]);
        prefxr[i] = min(prefxr[i - 1], xr[i]);
        prefyr[i] = min(prefyr[i - 1], yr[i]);
    }
    for(int i = n; i >= 0; i--) {
        suffxl[i] = max(suffxl[i + 1], xl[i]);
        suffyl[i] = max(suffyl[i + 1], yl[i]);
        suffxr[i] = min(suffxr[i + 1], xr[i]);
        suffyr[i] = min(suffyr[i + 1], yr[i]);
    }
    rep(i, 1, n + 1) {
        int XL = max(prefxl[i - 1], suffxl[i + 1]);
        int XR = min(prefxr[i - 1], suffxr[i + 1]);
        int YL = max(prefyl[i - 1], suffyl[i + 1]);
        int YR = min(prefyr[i - 1], suffyr[i + 1]);
        if(XL <= XR && YL <= YR) {
            cout << XL << ' ' << YL << '\n';
            return 0;
        }
    }
    assert(false);
}