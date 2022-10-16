#include<bits/stdc++.h>
using namespace std;
#define int long long
main () {
    int t;
    cin>>t;
    while(t--)
    {
        int h,w;
        cin>>h>>w;
        for(int x=1;x<=w;x++)
        cout<<(x%2==1);
        cout<<endl;
        for(int x=2;x<h;x++)
        {
            cout<<(x%2==1);
            for(int y=2;y<w;y++)
            cout<<0;
            cout<<(x%2==1&&x!=1)<<endl;
        }
        for(int x=1;x<=w;x++)
        cout<<(x%2==1&&(h%2==1||x!=1)&&(h%2==1||(x!=w&&x!=w-1)));
        cout<<endl;
        cout<<endl;
    }
}