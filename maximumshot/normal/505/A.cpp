// by maximumSHOT
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>
#include <stdio.h>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;
 
typedef long long LL;
typedef long double LD;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
 
LL Abs(LL x) {return (x >= 0?x : -x);}

bool solve()
{
    string a, b, c;

    cin >> a;

    for(int i(0);i < 26;i++)
    {
        b = char(i + 'a') + a;

        c = b;
        reverse(ALL(c));

        if(b == c)
        {
            cout << b << '\n';
            return true;
        }

        b = a + char(i + 'a');

        c = b;
        reverse(ALL(c));
        
        if(b == c)
        {
            cout << b << '\n';
            return true;
        }
    }

    for(int i(0);i < (int)a.size();i++)
    {
        b = c = "";

        for(int j(0);j < 26;j++)
        {
            b = a.substr(0, i + 1) + char(j + 'a') + a.substr(i + 1);
            c = b;
            reverse(ALL(c));

            if(b == c)
            {
                cout << b << '\n';
                return true;
            }
        }
    }

    puts("NA");

    return true;
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}