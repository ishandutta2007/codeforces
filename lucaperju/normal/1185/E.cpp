#include <bits/stdc++.h>

using namespace std;
char v[2003][2003];
int rzc[30][4];
int main()
{
    int t,n,m,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
            cin>>(v[i]+1);
        char mx='.';
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                if(v[i][j]!='.' && v[i][j]>mx)
                    mx=v[i][j];
            }
        }
        if(mx=='.')
        {
            cout<<"YES\n0\n";
            continue;
        }
        int x,y,a=0,b=0;
        char c;
        for(c=mx;c>='a';--c)
        {
            int okc=1;
            a=0;
            b=0;
            for(i=1;i<=n;++i)
            {
                for(j=1;j<=m;++j)
                {
                    if(v[i][j]==c && a==0)
                    {
                        a=i;
                        b=j;
                    }
                    if(v[i][j]==c)
                    {
                        x=i;
                        y=j;
                        if(x!=a && y!=b)
                            okc=0;
                    }
                }
            }
            int ca=0;
            int cb=0;
            for(i=1;i<=n;++i)
            {
                for(j=m;j>=1;--j)
                {
                    if(v[i][j]==c && ca==0)
                    {
                        ca=i;
                        cb=j;
                    }
                    if(v[i][j]==c)
                    {
                        if(i!=ca && j!=cb)
                            okc=0;
                    }
                }
            }
            if(okc==0)
            {
                cout<<"NO\n";
                break;
            }
            if(a==0)
            {
                for(i=1;i<=n;++i)
                    for(j=1;j<=m;++j)
                    {
                        if(v[i][j]!='.' && v[i][j]>c)
                        {
                            a=x=i;
                            b=y=j;
                        }
                    }
            }
            int ok=1;
            rzc[c-'a'+1][0]=a;
            rzc[c-'a'+1][1]=b;
            rzc[c-'a'+1][2]=x;
            rzc[c-'a'+1][3]=y;
            for(i=a;i<=x;++i)
                for(j=b;j<=y;++j)
                    if(v[i][j]=='.' || v[i][j]<c)
                        ok=0;
            if(ok==0||(a!=x && b!=y))
            {
                cout<<"NO\n";
                break;
            }
        }
        if(c!='a'-1)
            continue;
        cout<<"YES\n";
        cout<<mx-'a'+1<<'\n';
        for(i=1;i<=mx-'a'+1;++i)
            cout<<rzc[i][0]<<' '<<rzc[i][1]<<' '<<rzc[i][2]<<' '<<rzc[i][3]<<'\n';
    }
    return 0;
}