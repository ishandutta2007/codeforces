#include <bits/stdc++.h>

using namespace std;
int v[100005];
int main()
{
    long long i,j,n,m,b,k,s=0;
    cin>>b>>k;
    for(i=1;i<=k;++i)
    {
        cin>>v[i];
        if(i<k)
            s=s+b*1LL*v[i];
        else
            s+=v[i];
        s%=2;
    }
    if(s%2==0)
        cout<<"even";
    else
        cout<<"odd";
}