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

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        set<int> s;

        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            a = (a % n + n) % n;
            a = (i + a) % n;
            s.insert(a);
        }

        cout << (s.size() == n ? "YES" : "NO") << endl;
    }

    return 0;
}