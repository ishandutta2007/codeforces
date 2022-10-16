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

    int n, k;
    cin >> n >> k;

    if (k == 1 || k > 3){
        cout << -1 << endl;
        return 0;
    }

    if (k == 2){
        if (n <= 4){
            cout << -1 << endl;
            return 0;
        }

        cout << n - 1 << endl;
        for (int i = 1; i < n ; ++i)
            cout << i << " " << i + 1 << endl;
        return 0;
    }

    if (n < 4){
        cout << -1 << endl;
        return 0;
    }

    cout << 3 + (n - 4) * 2 << endl;
    cout << 1 << " " << 2 << endl;
    cout << 2 << " " << 3 << endl;
    cout << 3 << " " << 4 << endl;

    for (int i = 5; i <= n; ++i){
        cout << i << " " << 2 << endl;
        cout << i << " " << 3 << endl;
    }

    return 0;
}