#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,i;
    int a;
    cin>>a;
    if(a<1200)
        cout<<"1200";
    else if(a<1400)
        cout<<"1400";
    else if(a<1600)
        cout<<"1600";
    else if(a<1900)
        cout<<"1900";
    else if(a<2100)
        cout<<"2100";
    else if(a<2300)
        cout<<"2300";
    else if(a<2400)
        cout<<"2400";
    else if(a<2600)
        cout<<"2600";
    else
        cout<<"3000";
}