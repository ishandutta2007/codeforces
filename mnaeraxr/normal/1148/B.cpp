#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 n, m, ta, tb, k;

    cin >> n >> m >> ta >> tb >> k;

    if (min(n, m) <= k){
        cout << -1 << endl;
        return 0;
    }

    vector<int64> A(n), B(m);

    for (int i = 0; i < n; ++i)
        cin >> A[i];

    for (int i = 0; i < m; ++i)
        cin >> B[i];


    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int64 answer = 0;

    for (int i = 0; i <= k; ++i){
        int u = A[i];

        int64 p = lower_bound(B.begin(), B.end(), u + ta) - B.begin() + k - i;

        if (p >= m){
            cout << -1 << endl;
            return 0;
        } else {
            answer = max(answer, B[p] + tb);
        }
    }

    cout << answer << endl;

    return 0;
}