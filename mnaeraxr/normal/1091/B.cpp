#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int64 x = 0, y = 0;

    for (int i = 0; i < 2 * n; ++i){
        int64 a, b;
        cin >> a >> b;
        x += a;
        y += b;
    }

    assert(x % n == 0 && y % n == 0);
    cout << x / n << " " << y / n << endl;

    return 0;
}