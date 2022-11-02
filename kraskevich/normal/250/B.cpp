#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <stdlib.h>

using namespace std;

//#define DEBUG 1

string zero = "0000";

void solve(string s)
{
    int cnt = 0;
    string cur = "";
    string res = "";
    int pos = 0;
    
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == ':')
        {
            if (cur != "")
            {
                while (cur.length() < 4)
                    cur = '0' + cur;
                res += cur;
                res += ":";
                ++cnt;
                cur = "";
            }
            else
                pos = res.length();
        }
        else
            cur += s[i];
    if (cur != "")
    {
        ++cnt;
        while (cur.length() < 4)
            cur = '0' + cur;
        res += cur;
        res += ":";
    }
    
    for (int i = 0; i < 8 - cnt; ++i)
        res.insert(pos, zero + ":");
    
    if (res[res.length() - 1] == ':')
        res.erase(res.length() - 1, res.length());
    
    cout << res << endl;
}

int main()
{
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
    #endif
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        solve(s);
    }
    
    return 0;
}