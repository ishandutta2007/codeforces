#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>
#include <map>
#include <cstring>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, q;
        cin >> a >> b >> q;

        int tot = a * b;
        vector<int> total(tot);

        for (int i = 1; i < tot; ++i)
        {
            total[i] = total[i - 1];
            if (i % b % a != i % a % b)
                total[i]++;
        }

        function<long long(long long)> get = [&](long long n) {
            return 1LL * n / tot * total.back() + total[n % tot];
        };

        while (q--)
        {
            long long l, r;
            cin >> l >> r;

            cout << get(r) - get(l - 1) << " ";
        }
        cout << endl;
    }

    return 0;
}