#include <bits/stdc++.h>

using namespace std;
char vaux[55];
int b[55],b1[55];
char rz[55];
int fv[30];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t,m,k,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>t;
    while(t--)
    {
        cin>>(vaux+1);
        n=strlen(vaux+1);
        cin>>m;
        for(i=1;i<=m;++i)
            cin>>b[i];
        for(i=0;i<=28;++i)
            fv[i]=0;
        for(i=1;i<=n;++i)
            fv[vaux[i]-'a']++;
        int charc='z'-'a';
        for(int idk=1;idk<=26;++idk)
        {
            int cnt=0;
            for(i=1;i<=m;++i)
            {
                if(b[i]==0)
                    ++cnt;
            }
            while(fv[charc]<cnt)
                --charc;
            for(i=1;i<=m;++i)
                if(b[i]==0)
                    rz[i]=charc+'a';
            for(i=1;i<=m;++i)
                b1[i]=b[i];
            for(i=1;i<=m;++i)
            {
                if(b1[i]==0)
                {
                    for(j=1;j<=m;++j)
                    {
                        if(b1[j]>0)
                        {
                            b[j]-=max(i-j,j-i);
                        }
                    }
                }
            }
            for(i=1;i<=m;++i)
                if(b1[i]==0)
                    b[i]=-1;
            --charc;
        }
        rz[m+1]=0;
        cout<<(rz+1)<<'\n';
    }
    return 0;
}