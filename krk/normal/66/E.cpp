#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

ll n, a[Maxn], b[Maxn];
ll tol[Maxn], tor[Maxn];
vector <int> res;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    // to left
    ll gas = a[0];
    for (int i = n - 1; i > 0; i--) {
        gas -= b[i];
        if (gas < 0) {
                tol[0] += -gas; gas = 0;
        }
        gas += a[i];
    }
    for (int i = 1; i < n; i++)
        tol[i] = tol[i - 1] - (a[i] - b[i - 1]);
    // to right
    gas = a[n - 1];
    for (int i = 0; i < n - 1; i++) {
        gas -= b[(i + n - 1) % n];
        if (gas < 0) {
                tor[n - 1] += -gas; gas = 0;
        }
        gas += a[i];
    }
    for (int i = n - 2; i >= 0; i--)
        tor[i] = tor[i + 1] - (a[i] - b[i]);
    // Find good points
    for (int i = 0; i < n; i++)
        if (tol[i] == 0 || tor[i] == 0) res.push_back(i + 1);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size()? " ": "\n");
    return 0;
}