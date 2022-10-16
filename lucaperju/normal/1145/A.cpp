#include <bits/stdc++.h>

using namespace std;
int v[20];
int verif (int a, int b)
{
    for(int i=a+1;i<=b;++i)
        if(v[i]<v[i-1])
            return false;
    return true;
}
int main()
{
    long long t,n,i,j,mn=100003LL*100003LL,k,mx=0,tot,m,obj,st,cntp=0,cnti=0,s=0,pz;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=n;i>=1;i/=2)
    {
        for(j=1;j+i-1<=n;j+=i)
        {
            if(verif(j,j+i-1))
            {
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}