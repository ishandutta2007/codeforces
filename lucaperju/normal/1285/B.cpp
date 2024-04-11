#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    long long a,b,x,y,rz=0,n,root,m,w,i,j,k=0,pas=1<<15,sc=0,cnt=0,mn=0,nr1=0,nr2=0,mx=0,catc=0;
    long long t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sc=0;
        long long st=0;
        long long ok=0;
        mx=0;
        for(i=1;i<=n;++i)
        {
            cin>>a;
            st+=a;
            sc+=a;
            if(sc<=0)
            {
                sc=0;
                ok=1;
            }
            if(ok || i!=n)
                mx=max(mx,sc);
        }
        if(st>mx)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}