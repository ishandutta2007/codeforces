#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>




int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r" stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> l;
    vector<int> r;
    bool pl = true;
    bool pr = false;
    l.push_back(0);
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i - 1] == 'l')
        {
            if (pl)
                r.push_back(l.back()), l.back() = i;
            else
                l.push_back(i);
            pl = true;
            pr = false;
        }
        else
        {
            if (pr)
                l.push_back(r.back()), r.back() = i;
            else
                r.push_back(i);
            pl = false;
            pr = true;
        }
    }

    for (int x: l)
        cout << x + 1 << " ";
    reverse(r.begin(), r.end());
    for (int x: r)
        cout << x + 1 << " ";


    return 0;
}