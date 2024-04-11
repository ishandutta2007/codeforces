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

using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t-- > 0)
    {

        int n;
        cin >> n;

        if (n == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i + 1 < n; ++i)
                cout << 3;
            cout << 4 << endl;
        }
    }
    return 0;
}