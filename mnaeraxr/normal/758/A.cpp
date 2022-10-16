#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int64 s = 0, m = 0;

    int n; cin >> n;

    for (int i = 0; i < n; ++i){
        int64 v; cin >> v;
        m = max(m, v);
        s += v;
    }

    cout << m * n - s << endl;

    return 0;
}