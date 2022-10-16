#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int tree[maxn];
int total[maxn];
double E[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 2; i <= n; ++i)
        cin >> tree[i];

    for (int i = n; i; --i){
        total[i]++;
        total[tree[i]] += total[i];
    }

    E[1] = 1.0;

    cout.precision(17);

    cout << fixed << E[1] << " ";

    for (int i = 2; i <= n; ++i){
        E[i] = E[tree[i]] + 1.0 + 0.5 * (total[tree[i]] - total[i] - 1);
        cout << fixed << E[i] << " ";
    }

    cout << endl;

    return 0;
}