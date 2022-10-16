#include <bits/stdc++.h>
using namespace std;
int v[5005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,i,j,n,t;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        int catc=(i-1)/2;
        if(catc<=m)
            m-=catc,v[i]=i;
        else
        {
            v[i]=i+(catc-m)*2;
            m=0;
            break;
        }
    }
    if(m!=0)
    {
        cout<<-1<<'\n';
        return 0;
    }
    int vlc=1000000;
    for(++i;i<=n;++i)
    {
        v[i]=vlc;
        vlc+=100001;
    }
    for(i=1;i<=n;++i)
        cout<<v[i]<<' ';
    return 0;
}