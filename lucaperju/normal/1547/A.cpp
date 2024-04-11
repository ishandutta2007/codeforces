#include <bits/stdc++.h>
using namespace std;
long long rz[1000003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long q,m,i,j,l,r,t,n;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,x,y;
        cin>>a>>b>>c>>d>>x>>y;
        long long s=max(a,c)-min(a,c)+max(b,d)-min(b,d);
        if(a==x && c==x && min(b,d)<=y && y<=max(b,d))
            s+=2;
        if(b==y && y==d && min(a,c)<=x && x<=max(a,c))
            s+=2;
        cout<<s<<'\n';
    }
    return 0;
}