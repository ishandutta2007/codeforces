#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int64 sqr(int64 v){
    return v * v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int64 n;
    cin >> n;

    int64 value = 2;
    for (int64 i = 1; i <= n; ++i){
        int64 cur = i * sqr(i + 1) - value / i;
        cout << cur << endl;
        value = i*(i+1);
        // cout << value << endl;
    }


    return 0;
}