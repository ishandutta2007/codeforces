#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int64 fun(int64 n, int64 d){
    int64 q = n / d;

    int64 x = q * (q - 1) / 2 * d + q;

    return x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 n; cin >> n;

    set<int64> F;

    for (int64 i = 1; i * i <= n; ++i){
        if (n % i == 0){
            F.insert(fun(n, i));
            F.insert(fun(n, n / i));
        }
    }

    for (auto x : F)
        cout << x << " ";

    return 0;
}