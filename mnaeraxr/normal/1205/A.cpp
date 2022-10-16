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

    if (n & 1){
        cout << "YES" << endl;
        vector<int> ans(2 * n);

        for (int i = 0; i < 2 * n; i += 2){
            int a = i + 1, b = i + 2;
            if ((i / 2) & 1) swap(a, b);
            ans[i / 2] = a;
            ans[i / 2 + n] = b;
        }

        for (int i = 0; i < 2 * n; ++i){
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}