/*Chtholly is the best girl.*/
#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b> a/c)
            cout<<a/c - (b-(a/c) + c-2)/(c-1)<<"\n";
        else
            cout<<b<<"\n";
    }
    return 0;
}