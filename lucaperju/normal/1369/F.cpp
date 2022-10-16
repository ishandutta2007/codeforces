#include <bits/stdc++.h>
using namespace std;
bool verif (long long s, long long e)
{
    while(1)
    {
        if(e%2LL==1LL || s>e/2LL)
        {
            if(s%2LL!=e%2LL)
                return true;
            return false;
        }
        if(s>(e/2LL)/2LL)
            return true;
        e/=2LL;
        e/=2LL;
    }
}
long long s[100005],e[100005];
int win[100005],lose[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j,n,t,m,k,n1;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>s[i]>>e[i];
    for(i=1;i<=n;++i)
    {
        if(verif(s[i],e[i]))
            win[i]=1;
        else
            win[i]=0;
        if(verif(s[i],2LL*e[i]))
            lose[i]=1;
        else
            lose[i]=0;
    }
    int need=1;
    for(i=n;i>=2;--i)
    {
        if(need==1)
        {
            if(win[i]==1)
                need=0;
            else
                need=1;
        }
        else
        {
            if(lose[i]==1)
                need=0;
            else
                need=1;
        }
    }
    if(need==0)
    {
        if(lose[1])
            cout<<1<<' ';
        else
            cout<<0<<' ';
    }
    else
    {
        if(win[1])
            cout<<1<<' ';
        else
            cout<<0<<' ';
    }
    need=0;
    for(i=n;i>=2;--i)
    {
        if(need==1)
        {
            if(win[i]==1)
                need=0;
            else
                need=1;
        }
        else
        {
            if(lose[i]==1)
                need=0;
            else
                need=1;
        }
    }
    if(need==0)
    {
        if(lose[1])
            cout<<1;
        else
            cout<<0;
    }
    else
    {
        if(win[1])
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}
///