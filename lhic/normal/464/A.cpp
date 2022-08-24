#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

typedef long long ll;
typedef long double ld;

const int MAX_N = -1;


using namespace std;

int n, p;
string s;


int can(int i)
{
    bool cc[27] = {};
    for (int j = s[i] - 'a' + 1; j < p; ++j)
        cc[j] = 1;
    if (i > 1)
        cc[s[i - 2] - 'a'] = 0;
    if (i > 0)
        cc[s[i - 1] - 'a'] = 0;
    for (int i = 0; i < p; ++i)
        if (cc[i])
            return 'a' + i;
    return -1;
}


int can2(int i)
{
    bool cc[27] = {};
    for (int j = 0; j < p; ++j)
        cc[j] = 1;
    if (i > 1)
        cc[s[i - 2] - 'a'] = 0;
    if (i > 0)
        cc[s[i - 1] - 'a'] = 0;
    for (int i = 0; i < p; ++i)
        if (cc[i])
            return 'a' + i;
    return -1;
}


int main()
{
    cin >> n >> p;
    cin >> s;
    int st = -1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (can(i) != -1)
        {
            st = i;
            break;
        }
    }
    if (st == -1)
    {
        cout << "NO";
        return 0;
    }
    s[st] = can(st);
    for (int i = st + 1; i < n; ++i)
    {
        s[i] = 'a';
        if (can2(i) != -1)
        {
            s[i] = can2(i);
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << s;
    return 0;
}