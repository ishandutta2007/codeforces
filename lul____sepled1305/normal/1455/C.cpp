#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(y!=0 && x!=0)
            cout<<x-1<<' '<<y<<endl;
        else
            cout<<x<<' '<<y<<endl;
    }
}