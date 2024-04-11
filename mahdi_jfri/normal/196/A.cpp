#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
using namespace std;
bool fin(string a, char b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b){return 1;}
    }
    return 0;
}
int fin2(string a, char b)
{
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b){t += 1;}
    }
    return t;
}

int main()
{
    string n, ans = "";
    cin >> n;
    for(int i = 26; i >= 0; i--)
    {
        char x = 'a' + i;
        int po = fin2(n, x);
        if (po != 0)
        {
            for (int j = 0; j < po; j++)
            {
                cout << x;
            }
            for (int j = n.size()-1; j >= 0; j--)
            {
                if (n[j] == x){n = n.substr(j, n.size()); break;}
            }

        }
    }
}