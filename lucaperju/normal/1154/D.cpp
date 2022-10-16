#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    long long p,add=1,t,h,n,i,j,mn=99999,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,s=0,nri=0,b2,a3,b3,pz=1;
    int a,b;
    cin>>n>>b>>a;
    int cb=b,ca=a;
    for(i=1;i<=n;++i)
    {
        if(a==b && a==0)
            break;
        int vl;
        cin>>vl;
        if(vl==0)
        {
            if(a!=0)
            {
                --a;
                continue;
            }
            else
            {
                --b;
                continue;
            }
        }
        else
        {
            if(a==ca || b==0)
            {
                --a;
                continue;
            }
            else
            {
                --b;
                ++a;
                continue;
            }
        }
    }
    cout<<i-1;
    return 0;
}