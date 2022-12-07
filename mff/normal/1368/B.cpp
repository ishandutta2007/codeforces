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

    long long n;
    cin >> n;

    string codeforces = "codeforces";

    vector<int> s(codeforces.length(), 1);

    long long ans = 1;
    int p = 0;

    while (ans < n)
    {
        ans = ans / s[p];
        ans *= ++s[p];
        ++p;
        if (p == s.size())
            p = 0;
    }

    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = 0; j < s[i]; ++j)
            cout << codeforces[i];
    }
    cout << endl;

    return 0;
}