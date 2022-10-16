#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>

#include <map>
#include <math.h>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <stdint.h>

#include <experimental/optional>

#include <utility>

#include <tuple>

#include <random>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int value = 0;

    int a = s[0] - 'A';
    int b = s[1] - 'A';

    for (int i = 2; i < s.length(); i++)
    {
        int c = s[i] - 'A';
        
        if ((a + b) % 26 != c)
        {
            cout << "NO" << endl;
            return 0;
        }

        a = b;
        b = c;
    }

    cout << "YES" << endl;
    return 0;
}