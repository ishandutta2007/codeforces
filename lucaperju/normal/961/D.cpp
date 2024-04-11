#include <bits/stdc++.h>
using namespace std;
struct ura
{
    long long x,y;
}v[100005];
bool coli (ura a, ura b, ura c)
{
    long long val;
    val=a.x*1LL*(b.y-c.y);
    val=val+b.x*1LL*(c.y-a.y);
    val=val+c.x*1LL*(a.y-b.y);
    return (val==0);
}
int main()
{
    long long n,i,j,m,mn=9999999,pz,s=0,x,y,k=1,mx=0,cnt=0,val=0,st,dr,nr0=0,nr1=0,put=1,idk=0;
    cin>>n;
    if(n<=4)
    {
        cout<<"YES";
        return 0;
    }
    for(i=1;i<=n;++i)
        cin>>v[i].x>>v[i].y;
    pz=-1;
    for(i=4;i<=n;++i)
    {
        if(coli(v[1],v[2],v[i]))
            continue;
        if(pz==-1)
            pz=i;
        else if(!coli(v[3],v[pz],v[i]))
            break;
    }
    if(i==n+1)
    {
        cout<<"YES";
        return 0;
    }
    pz=-1;
    for(i=4;i<=n;++i)
    {
        if(coli(v[1],v[3],v[i]))
            continue;
        if(pz==-1)
            pz=i;
        else if(!coli(v[2],v[pz],v[i]))
            break;
    }
    if(i==n+1)
    {
        cout<<"YES";
        return 0;
    }
    pz=-1;
    for(i=4;i<=n;++i)
    {
        if(coli(v[2],v[3],v[i]))
            continue;
        if(pz==-1)
            pz=i;
        else if(!coli(v[1],v[pz],v[i]))
            break;
    }
    if(i==n+1)
    {
        cout<<"YES";
        return 0;
    }
    if(coli(v[1],v[2],v[3]))
    {
        int pz1=-1;
        pz=-1;
        for(i=4;i<=n;++i)
        {
            if(coli(v[2],v[3],v[i]))
                continue;
            if(pz1==-1)
                pz1=i;
            else
                if(pz==-1)
                    pz=i;
            else if(!coli(v[pz1],v[pz],v[i]))
                break;
        }
        if(i>n)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}