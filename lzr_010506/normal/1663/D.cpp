//
// Created by onglu on 2022/3/14.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    int x;
    cin >> a >> x;
    if(a == "ABC")
    {
        if(x < 2000) puts("yes");
        else puts("no");
    }
    else if(a == "ARC") 
    {
        if(x < 2800) puts("yes");
        else puts("no");
    }
    else {
        if(x >= 1200) puts("yes");
        else puts("no");
    }
}