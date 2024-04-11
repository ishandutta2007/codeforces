#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<long long> a(3);
    cin >> a[0] >> a[1] >> a[2];

    sort(a.begin(), a.end());

    cout << (a[1] + a[0] - 1) * (a[2] + a[0] - 1) - (a[0]) * (a[0] - 1) << endl;

    return 0;
}