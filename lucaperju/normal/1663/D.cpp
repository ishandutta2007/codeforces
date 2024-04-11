#include <bits/stdc++.h>
using namespace std;
string v;
int main()
{
    ios_base::sync_with_stdio(false);
    int x;
    cin>>v;
    cin>>x;
    if (v=="AGC")
    {
        if(x<1200)
            cout<<"no\n";
        else
            cout<<"yes\n";
    }
    else if(v=="ABC")
    {
        if(x<2000)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    else
    {
        if(x<2800)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
}