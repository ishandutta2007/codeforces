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
        string s;
        cin >> s;

        bool ok = true;
        for (int i = 0; i < (int)s.length(); ++i)
        {
            if (s[i] != s[0])
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            cout << s << endl;
        }
        else
        {
            for (int i = 0; i < (int)s.length(); ++i)
                cout << "01";
            cout << endl;
        }
    }

    return 0;
}