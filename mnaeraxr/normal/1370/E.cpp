#include <algorithm>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <array>
#include <complex>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int ones = 0;
    int ans = 0;

    queue<int> pairs[2];
    queue<int> alone[2];

    for (int i = 0; i < a.size(); ++i)
    {
        ones += a[i] == '1';
        ones -= b[i] == '1';

        if (a[i] != b[i])
        {
            int v = a[i] - '0';

            if (alone[v ^ 1].empty())
            {
                alone[v].push(i);
            }
            else
            {
                if (!pairs[v].empty() && pairs[v].front() < alone[v ^ 1].front())
                {
                    pairs[v].pop();
                }
                else
                {
                    ans++;
                }

                pairs[v].push(i);
                alone[v ^ 1].pop();
            }
        }
    }

    if (ones != 0)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}