#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#include <chrono>
#include <string>
#include <assert.h>

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, b, n;
    cin >> k >> b >> n;

    map<int, int> freq;
    freq[0]++;

    int cont_zeros = 0;
    int cur_mod = 0;
    long long total_zeros = 0;
    long long total_mod = 0;

    for (int i = 0; i < n; ++i)
    {
        int u;
        cin >> u;

        if (u == 0)
        {
            cont_zeros++;
            total_zeros += cont_zeros;
        }
        else
        {
            cont_zeros = 0;
        }

        cur_mod = (cur_mod + u) % (k - 1);
        int tt = (k - 1 + cur_mod - b) % (k - 1);
        total_mod += freq[tt];
        freq[cur_mod]++;
    }

    if (b == 0)
    {
        cout << total_zeros << endl;
    }
    else if (b == k - 1)
    {
        cout << total_mod - total_zeros << endl;
    }
    else
    {
        cout << total_mod << endl;
    }

    return 0;
}