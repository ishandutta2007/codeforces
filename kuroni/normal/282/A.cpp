#include <bits/stdc++.h>
using namespace std;
main()
{
    int n, x=0;
    char str[4];
    cin>>n;
    while (n--)
    {
        scanf("%s \n", &str);
        if ((str[0] == '-')||(str[2] == '-')) x--; else x++;
    }
    cout<<x;
}