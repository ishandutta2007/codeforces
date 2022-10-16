#include <bits/stdc++.h>

using namespace std;
int ok[1000003];
int main()
{
    long long k,l,r,t,x,y;
    cin>>k>>l>>r>>t>>x>>y;
    if(y==x)
    {
        if(l<=k-x && k-x<=r || l<=k+x && k+x<=r)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        return 0;
    }
    if(y<x)
    {
        long long cnt=0;
        if(k+y>r)
        {
            k-=x;
            ++cnt;
        }
        if(k<l)
        {
            cout<<"No\n";
            return 0;
        }
        long long dst=k-l;
        dst/=(x-y);
        cnt+=dst;
        if(cnt>=t)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        return 0;
    }
    long long cnt=0;
    while(1)
    {
        if(ok[k%x]==1 || t-cnt<=(k-l)/x)
        {
            cout<<"Yes\n";
            return 0;
        }
        ok[k%x]=1;
        if(k+y<=r)
        {
            k+=y;
            k-=x;
            ++cnt;
            continue;
        }
        long long vlc=r-y-x;
        vlc-=vlc%x;
        vlc+=k%x;
        vlc-=x;
        while(vlc+x+y<=r)
            vlc+=x;
        if(vlc<l)
        {
            cout<<"No\n";
            return 0;
        }
        cnt+=(k-vlc)/x;
        k=vlc;
        k+=y;
        k-=x;
        ++cnt;
    }
}