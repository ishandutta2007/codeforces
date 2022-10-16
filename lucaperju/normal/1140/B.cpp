#include <bits/stdc++.h>
using namespace std;
char v[105];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t,h,n,i,j,m,mn=999999999,pz,s=0,y,k=0,mx=0,cnt=0,val=0,st,dr,nr0=0,nr1=0,put=1,idk=0,mxtot=-1,pzf,sf;
    cin>>t;
    while(t--)
    {
        cin>>n>>ws>>v;
        s=0;
        mx=n-1;
        for(i=0;i<n;++i)
            if(v[i]=='>')
                break;
        s+=i;
        for(j=n-1;j>0;--j)
            if(v[j]=='<')
                break;
        s=min(s,n-1-j);
        mx=min(mx,s);
        cout<<mx<<'\n';
    }
    return 0;
}