#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        vector<int>q1,q2;
        for(int x=1;x*x<=a;x++)
        if(a%x==0){q1.push_back(x);if(x*x!=a)q1.push_back(a/x);}
        for(int x=1;x*x<=b;x++)
        if(b%x==0){q2.push_back(x);if(x*x!=b)q2.push_back(b/x);}
        for(auto q:q1)
        for(auto w:q2)
        {
            int u=q*w,v=a*b/u;
            u*=a/u+1,v*=b/v+1;
            if(a<u&&u<=c&&b<v&&v<=d){cout<<u<<' '<<v<<endl;goto nxt;}
        }
        cout<<-1<<' '<<-1<<endl;
        nxt:;
    }
}