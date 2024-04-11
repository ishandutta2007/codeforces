#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int u = 0;

    for (int i = 1; i <= n; ++i){
        int v; cin >> v;

        if (v > u){
            cout << i << endl;
            return 0;
        }

        if (v == u) u++;
    }

    cout << -1 << endl;

    return 0;
}