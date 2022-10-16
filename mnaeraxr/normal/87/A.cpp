#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int64 lcm(int64 u, int64 v){
    return u / __gcd(u, v) * v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 a, b;
    cin >> a >> b;

    int64 l = lcm(a, b);
    bool s = false;

    if (a > b){
        s = true;
        swap(a, b);
    }

    int64 v = 0;

    for (int64 i = b; i <= l; i += b)
        v += i - (i - 1) / a * a;

    if (2 * v == l) cout << "Equal" << endl;
    else{
        if (s) v = l - v;

        if (v < l - v) cout << "Dasha" << endl;
        else cout << "Masha" << endl;
    }


    return 0;
}