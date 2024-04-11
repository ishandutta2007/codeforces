#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)cout<<'a'<<endl;
        else{
        for(int x=1;x<=(n-2)/2;x++)
        cout<<'a';
        cout<<'b';
        for(int x=1;x<=(n-2)/2+1;x++)
        cout<<'a';
        for(int x=1;x<=n-(n-2)/2-(n-2)/2-2;x++)
        cout<<char('b'+x);
        cout<<endl;}
    }
}