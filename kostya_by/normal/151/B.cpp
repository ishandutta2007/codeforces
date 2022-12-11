//
//  main.cpp
//  phone_numbers
//
//  Created by Sokol Kostya's MacBook on 30.04.11.
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

int numa, numb, numc, n, aa = 0, bb = 0, cc = 0, a, b, c, m;
vector<string> taxi, pizza, girls;
string name;

bool check_taxi()
{
    if (a == b && b == c)
    {
        if (a % 10 == a / 10) return true;
        return false;
    }
    return false;
}

bool check_pizza()
{
    int a1 = a / 10, a2 = a % 10, b1 = b / 10, b2 = b % 10, c1 = c / 10, c2 = c % 10;
    if (a1 > a2 && a2 > b1 && b1 > b2 && b2 > c1 && c1 > c2) return true;
    return false;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int q = 0; q < n; q++)
    {
        cin >> m >> name;
        numa = numb = numc = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d-%d-%d", &a, &b, &c);
            if (check_taxi() == true)
            {
                ++numa;
                continue;
            }
            if (check_pizza() == true)
            {
                ++numb;
                continue;
            }
            ++numc;
        }
        if (numa > aa)
        {
            aa = numa;
            taxi.clear();
        }
        if (numa == aa) taxi.pb( name );
        
        if (numb > bb)
        {
            bb = numb;
            pizza.clear();
        }
        if (numb == bb) pizza.pb( name );
        
        if (numc > cc)
        {
            cc = numc;
            girls.clear();
        }
        if (numc == cc) girls.pb( name );
    }
    cout << "If you want to call a taxi, you should call:";
    for (int i = 0; i < taxi.size(); i++) 
    {
        cout << " " << taxi[i];
        if (i + 1 == taxi.size()) cout << '.'; else cout << ',';
    }
    cout << endl;
    
    cout << "If you want to order a pizza, you should call:";
    for (int i = 0; i < pizza.size(); i++) 
    {
        cout << " " << pizza[i];
        if (i + 1 == pizza.size()) cout << '.'; else cout << ',';
    }
    cout << endl;
    
    cout << "If you want to go to a cafe with a wonderful girl, you should call:";
    for (int i = 0; i < girls.size(); i++) 
    {
        cout << " " << girls[i];
        if (i + 1 == girls.size()) cout << '.'; else cout << ',';
    }
    cout << endl;
    return 0;
}