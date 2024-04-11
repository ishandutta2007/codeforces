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

    int n; cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }

    for (int i = 0; i < (1 << n); ++i){
        int deg = 0;

        for (int j = 0; j < n; ++j){
            if (i >> j & 1)
                deg += v[j];
            else
                deg -= v[j];
        }

        if (deg % 360 == 0){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}