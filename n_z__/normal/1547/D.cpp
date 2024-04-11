#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int lst;
        cout<<0<<' ';
        cin>>lst;
        for(int x=2,y;x<=n;x++)
        cin>>y,cout<<((y^lst)&lst)<<' ',lst|=y;
        cout<<endl;
    }
}