#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
char a[103],b[103];
int fv[305];
int main()
{
    ios_base::sync_with_stdio(0);
    long long m,i,j,k,s=0,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int la=strlen(a);
        int lb=strlen(b);
        for(i=0;i<=300;++i)
            fv[i]=0;
        int cnt=0,ok=0;
        for(i=0;i<la;++i)
        {
            ++fv[a[i]];
            if(fv[a[i]]==1)
                ++cnt;
        }
        for(i=0;i<la;++i)
        {
            --fv[b[i]];
            if(fv[b[i]]==0)
                --cnt;
            if(fv[b[i]]==-1)
                ++cnt;
            if(cnt==0)
                ok=1;
        }
        for(i=la;i<lb;++i)
        {
            --fv[b[i]];
            if(fv[b[i]]==0)
                --cnt;
            if(fv[b[i]]==-1)
                ++cnt;
            ++fv[b[i-la]];
            if(fv[b[i-la]]==1)
                ++cnt;
            if(fv[b[i-la]]==0)
                --cnt;
            if(cnt==0)
                ok=1;
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}