#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

typedef tree<int, null_type, less<int>,
        rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int maxn = 200010;
int bit[maxn];

int query(int idx){
    int answer = 0;
    while (idx){
        answer += bit[idx];
        idx -= idx & -idx;
    }
    return answer;
}

void update(int idx){
    if (query(idx) - query(idx - 1))
        return;

    while (idx < maxn){
        bit[idx]++;
        idx += idx & -idx;
    }
}

int64 comb(int64 a){
    return a * (a + 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<pii> A(n);

    vector<int> X;

    for (int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        A[i] = pii(-y, x);
        X.push_back(x);
    }

    sort(X.begin(), X.end());
    X.resize(unique(X.begin(), X.end()) - X.begin());

    sort(A.begin(), A.end());

    int64 answer = 0;

    for (int i = 0, j; i < n; i = j){
        int prevx = 0;
        int64 old = 0;

        for (j = i; j < n && A[j].first == A[i].first; ++j){
            int x = A[j].second;
            x = lower_bound(X.begin(), X.end(), x) - X.begin() + 1;

            int U = query(x - 1);
            int V = query(prevx);
            old += comb(U - V);
            prevx = x;

            update(x);
        }

        int U = query(maxn - 1);
        int V = query(prevx);
        old += comb(U - V);

        int64 total = comb(U);

        answer += total - old;

        // cout << answer << endl;
    }

    cout << answer << endl;

    return 0;
}