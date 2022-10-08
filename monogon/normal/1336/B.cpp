
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n[3];
vector<ll> v[3];

ll fun(ll a, ll b, ll c) {
    return (a - b) * (a - b) + (b - c) * (b - c) + (a - c) * (a - c);
}

ll solve(vector<ll> &A, vector<ll> &B, vector<ll> &C) {
    ll ans = LLONG_MAX;
    for(int i = 0; i < (int) A.size(); i++) {
        int j = lower_bound(B.begin(), B.end(), A[i] + 1) - B.begin() - 1;
        int k = lower_bound(C.begin(), C.end(), A[i]) - C.begin();
        if(j < 0) j = 0;
        if(k == (int) C.size()) k--;
        ans = min(ans, fun(A[i], B[j], C[k]));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        for(int i = 0; i < 3; i++) {
            cin >> n[i];
            v[i].resize(n[i]);
        }
        for(int k = 0; k < 3; k++) {
            for(int i = 0; i < n[k]; i++) {
                cin >> v[k][i];
            }
            sort(v[k].begin(), v[k].end());
        }
        vector<int> perm = {0, 1, 2};
        ll m = LLONG_MAX;
        do {
            m = min(m, solve(v[perm[0]], v[perm[1]], v[perm[2]]));
        }while(next_permutation(perm.begin(), perm.end()));
        cout << m << '\n';
    }
}