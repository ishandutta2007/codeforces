#include <bits/stdc++.h>

using namespace std;
char v[11][11];
int n,m;
char vc[11];
bool check ()
{
    int i,j;
    for(i=1;i<=n;++i)
    {
        int cnt=0;
        for(j=1;j<=m;++j)
            if(v[i][j]!=vc[j])
                ++cnt;
        if(cnt>1)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
            cin>>(v[i]+1);
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                vc[j]=v[i][j];
            if(check())
                break;
        }
        if(i<=n)
        {
            for(i=1;i<=m;++i)
                cout<<vc[i];
            cout<<'\n';
            continue;
        }
        int s1;
        for(s1=1;s1<=n;++s1)
        {
            for(int s2=s1+1;s2<=n;++s2)
            {
                for(int p1=1;p1<=m;++p1)
                {
                    for(j=1;j<=m;++j)
                        vc[j]=v[s1][j];
                    vc[p1]=v[s2][p1];
                    if(check())
                    {
                        s1=s2=p1=1000;
                        break;
                    }
                }
            }
        }
        if(s1>=999)
        {
            for(i=1;i<=m;++i)
                cout<<vc[i];
            cout<<'\n';
        }
        else
            cout<<-1<<'\n';
    }
    return 0;
}