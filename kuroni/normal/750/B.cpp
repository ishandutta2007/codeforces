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
    int n, cur = 0, t, prev;
    string s;
    cin>>n;
    while (n--)
    {
        cin>>t>>s;
        if (((cur == 0) || (cur == 20000)) && ((s == "East") || (s == "West")))
        {
            cout<<"NO";
            return 0;
        }
        if (s == "North") cur -= t;
        if (s == "South") cur += t;
        if ((cur < 0) || (cur > 20000))
        {
            cout<<"NO";
            return 0;
        }
    }
    if (cur == 0) cout<<"YES"; else cout<<"NO";
}