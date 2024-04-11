#include <bits/stdc++.h>

using namespace std;
int cmmdc (int a, int  b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(cmmdc(a,b)==1)
            cout<<"Finite\n";
        else
            cout<<"Infinite\n";
    }
    return 0;
}