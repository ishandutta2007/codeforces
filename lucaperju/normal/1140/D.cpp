#include <bits/stdc++.h>
using namespace std;
struct ura
{
    long long tmp,val;
}v[300005];
long long heap[300003],elemx=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t,h,n,i,j,m,mn=999999999,pz,s=0,y,k=0,mx=0,cnt=0,val=0,st,dr,nr0=0,nr1=0,put=1,idk=0,mxtot=-1,pzf,sf;
    cin>>n;
    for(i=n;i>=3;--i)
    {
        s=s+i*1LL*(i-1);
    }
    cout<<s;
    return 0;
}