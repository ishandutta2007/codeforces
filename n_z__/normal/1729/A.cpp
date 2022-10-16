#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a-1<abs(c-b)+abs(c-1))cout<<1<<endl;
        else if(a-1>abs(c-b)+abs(c-1))cout<<2<<endl;
        else cout<<3<<endl;
    }
}