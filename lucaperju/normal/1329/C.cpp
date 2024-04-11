#include <bits/stdc++.h>
using namespace std;
int a[1048580],h,g;
int scoate (int pz)
{
    int vl=a[pz];
    while(1)
    if(pz*2>=(1<<h) || a[pz<<1]+a[pz*2+1]==0)
    {
        a[pz]=0;
        break;
    }
    else
    {
        if(a[pz<<1]>a[pz*2+1])
        {
            swap(a[pz<<1],a[pz]);
            pz<<=1;
        }
        else
        {
            swap(a[pz*2+1],a[pz]);
            pz=pz*2+1;
        }
    }
    return vl;
}
bool ok (int pz)
{
    while(1)
    if(pz*2>=(1<<h) || a[pz<<1]+a[pz*2+1]==0)
    {
        //a[pz]=0;
        break;
    }
    else
    {
        if(a[pz<<1]>a[pz*2+1])
        {
            //swap(a[pz<<1],a[pz]);
            pz<<=1;
        }
        else
        {
            //swap(a[pz*2+1],a[pz]);
            pz=pz*2+1;
        }
    }
    return pz>=(1<<g);
}
int r[1048580];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,i,j,m,t;
    cin>>t;
    while(t--)
    {
        long long rz=0;
        cin>>h>>g;
        for(i=1;i<(1<<h);++i)
        {
            cin>>a[i];
            rz+=a[i];
        }
        j=0;
        for(i=1;i<(1<<g);++i)
            while(ok(i))
            {
                rz-=scoate(i);
                r[++j]=i;
            }
        cout<<rz<<'\n';
        for(i=1;i<=((1<<h)-(1<<g));++i)
            cout<<r[i]<<' ';
        cout<<'\n';
    }
    return 0;
}