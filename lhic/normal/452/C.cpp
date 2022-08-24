#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cstring>

typedef long long ll;
typedef long double ld;

const int MAX_N = 110000;

using namespace std;


ld n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        cout << 1;
        return 0;
    }
    cout << fixed << setprecision(12) << 1 / n + (n - 1) * (m - 1) / ( (n * m - 1) * n);
    return 0;
}