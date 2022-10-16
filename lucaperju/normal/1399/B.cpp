#include <bits/stdc++.h>
using namespace std;
long long a[1003];
long long b[1003];
int main()
{
    long long t,n,m,i,j,x,y,k,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long am,bm;
        for(i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        for(i=1;i<=n;++i)
        {
            cin>>b[i];
        }
        am=a[1];
        bm=b[1];
        for(i=1;i<=n;++i)
        {
            am=min(am,a[i]);
            bm=min(bm,b[i]);
        }
        long long cnt=0;
        for(i=1;i<=n;++i)
        {
            long long ca=a[i]-am;
            long long cb=b[i]-bm;
            cnt+=ca+cb-(min(ca,cb));
        }
        cout<<cnt<<'\n';
    }
    return 0;
}