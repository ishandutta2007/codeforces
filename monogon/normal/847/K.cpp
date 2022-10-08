
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// each route has a sum of costs if we buy no travel cards
// buy a travel card, with change in cost of (f - value)
// only buy travel cards for most expensive routes
// at most k of them, and only if f - value < 0

const int N = 305;
int n, a, b, k, f;
ll cost = 0;
string s[N], t[N];
map<pair<string, string>, ll> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> k >> f;
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
        string S = s[i], T = t[i];
        if(S > T) swap(S, T);
        if(i > 0 && s[i] == t[i - 1]) {
            mp[{S, T}] += b;
        }else {
            mp[{S, T}] += a;
        }
    }
    vector<ll> ve;
    for(auto p : mp) {
        ve.push_back(p.second);
        cost += p.second;
    }
    sort(ve.rbegin(), ve.rend());
    for(int i = 0; i < (int) ve.size() && i < k; i++) {
        if(f - ve[i] < 0) {
            cost += f - ve[i];
        }else break;
    }
    cout << cost << endl;
}