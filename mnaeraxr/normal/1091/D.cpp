#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int64 mod = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int64> fak(n + 1);

    fak[0] = 1;

    for (int i = 1; i <= n; ++i)
        fak[i] = fak[i - 1] * i % mod;

    int64 answer = fak[n];
    int64 x = 1;

    for (int i = n; i; --i){
        x = x * i % mod;

        int64 y = x * (fak[i - 1] - 1) % mod;

        answer = (answer + y) % mod;
    }

    cout << answer << endl;

    return 0;
}