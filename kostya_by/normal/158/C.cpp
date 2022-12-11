//
//  main.cpp
//  taskC_real
//
//  Created by Sokol Kostya's MacBook on 04.03.11.
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

struct Tstate
{
    vector<string> s;
    void scan()
    {
        string ss, now = "";
        cin >> ss;
        if (ss[0] == '/') s.clear();
        ss = ss + '/';
        for (int i = 0; i < ss.size(); i++)
        {
            if (ss[i] == '/')
            {
                if (now == "") continue;
                if (now == "..") s.pop_back(); else s.push_back(now);
                now = "";
                continue;
            }
            now = now + ss[i];
        }
    }
    void print()
    {
        cout << "/";
        for (int i = 0; i < s.size(); i++) cout << s[i] << "/";
        cout << endl;
    }
};

Tstate state;
string command;
int n;

int main (int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "cd") state.scan();
        if (command == "pwd") state.print();
    }
    return 0;
}