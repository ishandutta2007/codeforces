#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long h,n,i,j,m,mn=999999999,pz,s=0,y,k=0,mx=0,cnt=0,val=0,st,dr,nr0=0,nr1=0,put=1,idk=0,mxtot=-1,pzf,sf;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    long long pr=100000000000LL;
    for(i=n;i>=1;--i)
    {
        if(min(v[i],pr)>0)
            s=s+min(v[i],pr);
        pr=min(v[i],pr)-1;
    }
    cout<<s;
    return 0;
}