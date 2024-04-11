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

    int n, k; cin >> n >> k;

    vector<int> C(n);
    vector<set<int>> U(5001);

    for (int i = 0, c = 0; i < n; ++i){
        int v; cin >> v;

        if (U[v].size() == k){
            cout << "NO" << endl;
            return 0;
        }

        while (U[v].find(c) != U[v].end())
            c = (c + 1) % k;

        U[v].insert(c);
        C[i] = c + 1;
        c = (c + 1) % k;
    }

    cout << "YES" << endl;

    for (auto x : C)
        cout << x << " ";

    return 0;
}