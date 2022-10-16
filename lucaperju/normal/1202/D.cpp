#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long k,t,i,j=0,cnt=1,n,m,is,js,ib,jb,s=0,mx=0,cur=0,q;
    cin>>t;
    while(t--)
    {
        int x,a,b,c,d;
        cin>>x;
        if(x<=100000-10)
        {
            for(i=1;i<=x;++i)
                cout<<1;
            cout<<"337\n";
            continue;
        }
        a=1;
        d=31622;
        b=x/31622;
        for(c=0;c<=31622;++c)
            if(b*d+c==x)
                break;
        b-=3;
        for(i=1;i<=a;++i)
            cout<<1;
        cout<<3;
        for(i=1;i<=b;++i)
            cout<<1;
        cout<<3;
        for(i=1;i<=c;++i)
            cout<<7;
        cout<<3;
        for(i=1;i<=d;++i)
            cout<<7;
        cout<<'\n';
    }
    return 0;
}