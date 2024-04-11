//
//  main.cpp
//  formating
//
//  Created by Sokol Kostya's MacBook on 12.05.11.
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
#include <cstdlib>
#include <ctime>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

string cur;
vector< string > arr;
char ss[333];
int n;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( ss );
    n = strlen( ss );
    for (int i = 0; i < n;)
    {
        if (ss[i] == ' ')
        {
            if (cur.size() != 0)
            {
                arr.pb( cur );
                cur = "";
            }
            ++i;
            continue;
        }
        if (ss[i] == ',')
        {
            if (cur.size() != 0)
            {
                arr.pb( cur );
                cur = "";
            }
            arr.pb( "," );
            ++i;
            continue;
        }
        if (ss[i] == '.')
        {
            if (cur.size() != 0)
            {
                arr.pb( cur );
                cur = "";
            }
            arr.pb( "..." );
            i += 3;
            continue;
        }
        cur = cur + ss[i];
        ++i;
    }
    if (cur.size() != 0)
    {
        arr.pb( cur );
        cur = "";
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i][0] == '.' && i != 0)
        {
            if (arr[i - 1] != ",") cout << " ";
        }
        if (arr[i][0] != '.' && arr[i][0] != ',' && i != 0)
        {
            if (arr[i - 1][0] != '.' && arr[i - 1][0] != ',') cout << " ";
        }
        cout << arr[i];
        if (arr[i] == "," && i != arr.size() - 1)
        {
            cout << " ";
        }
    }
    return 0;
}