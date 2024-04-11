#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int Maxn = 100005;
const int Maxd = 320;

int n;
int a[Maxn];
vector <int> V;
int where[Maxn];
int d, rmq[Maxd];
int res[Maxn];

int getRMQ(int pos)
{
    int res = -1;
    int poss = pos / d;
    for (int i = 0; i < poss; i++)
       res = max(res, rmq[i]);
    for (int i = poss * d; i < pos; i++)
       res = max(res, where[i]);
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n; d = int(sqrt(double(n)) + 0.5);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; V.push_back(a[i]);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    fill(where, where + Maxn, -1); fill(rmq, rmq + Maxd, -1);
    for (int i = n - 1; i >= 0; i--) {
        int ind = lower_bound(V.begin(), V.end(), a[i]) - V.begin();
        int st = getRMQ(ind);
        if (st == -1) res[i] = -1;
        else res[i] = st - i - 1;
        where[ind] = max(where[ind], i);
        rmq[ind / d] = max(rmq[ind / d], i);
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
}