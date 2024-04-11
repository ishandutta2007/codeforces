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

    int64 n, m, k;
    cin >> n >> m >> k;

    int64 lane = (k + 2 * m - 1) / (2 * m);
    int64 desk = (k - 1) % (2 * m);

    cout << lane << " " << desk / 2 + 1 << " " << (desk & 1 ? 'R' : 'L') << endl;



    return 0;
}