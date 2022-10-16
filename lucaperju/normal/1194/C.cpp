#include <bits/stdc++.h>

using namespace std;
char a[103],b[103],c[103];
int fv[200];
int d[103][103];
int main()
{
    int t,i,j,cnt=0,k,mn=2;
    cin>>t;
    while(t--)
    {
        int ok=0;
        cin>>a>>b>>c;
        int na=strlen(a);
        int nb=strlen(b);
        int nc=strlen(c);
        for(i=0;i<na;++i)
            ++fv[a[i]];
        for(i=0;i<nb;++i)
            --fv[b[i]];
        for(i=0;i<nc;++i)
            ++fv[c[i]];
        for(i=1;i<=199;++i)
        {
            if(fv[i]<0)
            {
                cout<<"NO\n";
                ok=1;
                break;
            }
        }
        for(i=1;i<=199;++i)
            fv[i]=0;
        for(i=0;i<na;++i)
            for(j=0;j<nb;++j)
                if(a[i]==b[j])
                    d[i+1][j+1]=d[i][j]+1;
                else
                    d[i+1][j+1]=max(d[i][j+1],d[i+1][j]);
        if(d[na][nb]!=na)
        {
            if(!ok)
                cout<<"NO\n";
            ok=1;
        }
        if(!ok)
            cout<<"YES\n";
    }
    return 0;
}