#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int64 lcm(int64 a, int64 b){
    return a / __gcd(a, b) * b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 n, m;
    cin >> n >> m;
    int64 w = 1;

    for (int i = 0; i < n; ++i){
        int64 v; cin >> v;
        w = lcm(w, __gcd(v, m));
    }

    cout << (m == w ? "Yes" : "No") << endl;

    return 0;
}