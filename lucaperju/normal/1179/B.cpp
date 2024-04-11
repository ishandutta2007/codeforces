#include <bits/stdc++.h>
using namespace std;
const long long mod=(1e9)+7;
int v[200005];
int rza[100005],rzb[100005];
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m,ta,tb,i,j,nrc=0,nrd=0,s=0,t,ok=0,a,b,c,d,rz=1,q,mx=-1,pz,k=0;
    cin>>n>>m;
    if(n==1 && m==1)
    {
        cout<<1<<' '<<1;
        return 0;
    }
    int i1=1,i2=n;
    while(i1<=i2)
    {
        int j1=1,j2=m;
        while(j1<=m)
        {
            cout<<i1<<' '<<j1<<'\n';
            if(j1>=j2 && i1==i2)
                break;
            cout<<i2<<' '<<j2<<'\n';
            ++j1;
            --j2;
            if(j1>j2 && i1==i2)
                break;
        }
        ++i1;
        --i2;
    }
    return 0;
}