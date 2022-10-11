#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <ios>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n, min1 = 0, max2 = 0, cur = 0, c, d = 0, i;
    bool div1 = 0, div2 = 0;
    cin>>n;
    for (i = 0; i < n; i++)
    {
        cin>>c>>d;
        if (d == 1)
        {
            if (!div1) min1 = cur; else min1 = min(min1, cur);
            div1 = 1;
        }
        else if (d == 2)
        {
            if (!div2) max2 = cur; else max2 = max(max2, cur);
            div2 = 1;
        }
        cur += c;
        //cout<<c<<" "<<d<<" "<<cur<<" "<<max2<<" "<<min1<<'\n';
    }
    if (!div2)
    {
        cout<<"Infinity";
        return 0;
    }
    if (!div1)
    {
        cout<<1899 - max2 + cur;
        return 0;
    }
    if (max2 >= min1)
            cout<<"Impossible";
    else
            cout<<1899 - max2 + cur;
}