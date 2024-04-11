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

string s;


int n;

int main()
{
    ios_base::sync_with_stdio(false);

    vector<string> vv = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

    cin >> n;
    cin >> s;

    for (int i = 0; i < vv.size(); ++i)
    {
        if (vv[i].size() != n)
            continue;
        bool fl = true;
        for (int j = 0; j < vv[i].size(); ++j)
            if (s[j] != '.' && vv[i][j] != s[j])
                fl = false;
        if (fl)
        {
            cout << vv[i];
            return 0;
        }

    }

    return 0;
}