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



int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    if (s[0] != '-')
    {
        cout << s;
        return 0;
    }
    int l = s.length();
    if (s[l - 1] > s[l - 2])
        s.erase(l - 1, 1);
    else
        s.erase(l - 2, 1);
    if (s == "-0")
        s = "0";
    cout << s;


    return 0;
}