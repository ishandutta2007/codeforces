#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 10;
const ll INF = (ll)1e15;
ll x[maxN], y[maxN];
ll man(pair < ll, ll > a, pair < ll, ll > b) {
    return (abs(a.first - b.first) + abs(a.second - b.second));
}
bool bad[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    srand(time(0));
    cin.tie(nullptr);
    int n;
    ll mnX = INF, mnY = INF, mxX = -INF, mxY = -INF;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        mnX = min(mnX, x[i]);
        mnY = min(mnY, y[i]);
        mxX = max(mxX, x[i]);
        mxY = max(mxY, y[i]);
    }
    ll for_big = 2 * (mxY - mnY) + 2 * (mxX - mnX);
    vector < pair < ll, ll > > intersting;
    for (int i = 1; i <= 3; i++) intersting.push_back(make_pair(x[i], y[i]));
    for (int i = 1; i <= n; i++) {
        if (x[i] == mxX || x[i] == mnX) {
            intersting.push_back(make_pair(x[i], y[i]));
            bad[i] = true;
        }
        else if (y[i] == mxY || y[i] == mnY) {
            bad[i] = true;
            intersting.push_back(make_pair(x[i], y[i]));
        }
    }
    ll opt = 0;
    for (int i = 0; i < intersting.size(); i++) {
        for (int j = i + 1; j < intersting.size(); j++) {
            for (int k = j + 1; k < intersting.size(); k++) {
                opt = max(opt, man(intersting[i], intersting[j]) + man(intersting[i], intersting[k]) + man(intersting[j], intersting[k]));
            }
        }
    }
    for (int i = 0; i < intersting.size(); i++) {
        for (int j = i + 1; j < intersting.size(); j++) {
            for (int k = 1; k <= n; k++) {
                if (bad[k]) continue;
                auto t = make_pair(x[k], y[k]);
                opt = max(opt, man(intersting[i], intersting[j]) + man(intersting[j], t) + man(intersting[i], t));
            }
        }
    }
    cout << opt << " ";
    for (int i = 4; i <= n; i++) cout << for_big << " ";
    return 0;
}