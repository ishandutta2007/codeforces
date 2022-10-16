#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

long long cost[101];
vector<long long> auc;

int main()
{
    long long n, m, sum = 0, t;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> cost[i];
        sum += cost[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> t;
        auc.push_back(cost[t]);
        sum -= cost[t];
    }
    sort(auc.begin(), auc.end());
    for (int i = auc.size() - 1; i >= 0; --i)
        sum += max(auc[i], sum);

    cout << sum;
    return 0;
}