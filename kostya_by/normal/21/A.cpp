//
//  main.cpp
//  jabber id
//
//  Created by Sokol Kostya's MacBook on 21.01.11.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

string ss, pattern = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789_", s;
vector<string> arr;

int main (int argc, const char * argv[])
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> ss;
    bool f1 = true, f2 = true;
    int val = 0;
    s = "";
    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i] == '@')
        {
            if (f1 == false)
            {
                cout << "NO";
                return 0;
            }
            f1 = false;
            if (s.size() < 1 || s.size() > 16)
            {
                cout << "NO";
                return 0;
            }
            s = "";
            continue;
        }
        if (ss[i] == '/')
        {
            if (f1 == true || f2 == false)
            {
                cout << "NO";
                return 0;
            }
            if (s.size() > 16 || s.size() < 1)
            {
                cout << "NO";
                return 0;
            }
            if (s.size() != 0) arr.push_back(s);
            if (arr.size() == 0)
            {
                cout << "NO";
                return 0;
            }
            f2 = false;
            val = arr.size() - 1;
            for (int j = 0; j < arr.size(); j++) val += arr[j].size();
            if (val > 32) 
            {
                cout << "NO";
                return 0;
            }
            s = "";
            continue;
        }
        if (ss[i] == '.')
        {
            if (f1 == true)
            {
                cout << "NO";
                return 0;
            }
            if (f2 == false)
            {
                cout << "NO";
                return 0;
            }
            if (s.size() < 1 || s.size() > 16)
            {
                cout << "NO";
                return 0;
            }
            arr.push_back(s);
            s = "";
            continue;
        }
        if (pattern.find_first_of(ss[i]) == string::npos)
        {
            cout << "NO";
            return 0;
        }
        s = s + ss[i];
    }
    if (f1 == false && f2 == true)
    {
        if (s.size() < 1 || s.size() > 16)
        {
            cout << "NO";
            return 0;
        }
        val += 1 + s.size();
    }
    if (f1 == false && f2 == false)
    {
        if (s.size() < 1 || s.size() > 16)
        {
            cout << "NO";
            return 0;
        }
    }
    if (f1 == true)
    {
        cout << "NO";
        return 0;
    }
    if (f1 == true || val == 0)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}