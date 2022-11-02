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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            s.erase(i, 1);
            break;
        }
    }
    if (s.length() == n)
        s.erase(s.length() - 1, 1);
    cout << s;


    return 0;
}