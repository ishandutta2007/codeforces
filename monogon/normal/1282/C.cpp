
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int m, n;
ll T, a, b, t, s, h;
bool hard[N];
vector<pair<ll, bool>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m;
    while(m--) {
        cin >> n >> T >> a >> b;
        ll acnt = 0, bcnt = 0;
        for(int i = 0; i < n; i++) {
            cin >> hard[i];
            acnt += !hard[i];
            bcnt += hard[i];
        }
        v.clear();
        for(int i = 0; i < n; i++) {
            cin >> t;
            v.emplace_back(t, hard[i]);
        }
        v.emplace_back(T + 1, false);
        sort(v.begin(), v.end());
        ll sum = 0;
        ll best = 0;
        for(int i = 0; i <= n; i++) {
            tie(s, h) = v[i];
            if(sum <= s - 1) {
                ll numa = min(acnt, ((s - 1) - sum) / a);
                ll numb = min(bcnt, ((s - 1) - sum - numa * a) / b);
                best = max(best, i + numa + numb);
            }
            sum += (h ? b : a);
            (h ? bcnt : acnt)--;
        }
        cout << best << endl;
    }
}