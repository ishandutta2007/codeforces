#include <bits/stdc++.h>
using namespace std;
int v[200005],fv[205];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j=0,t,mx=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int rz=0;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(int val=1;val<=200;++val)
        {
            int cnt=0;
            for(i=1;i<=n;++i)
                if(v[i]==val)
                    ++cnt;
            if(cnt==0)
                continue;
            int cat=cnt/2;
            int nrc=0,st,dr;
            for(st=1;nrc<cat;++st)
            {
                if(v[st]==val)
                    ++nrc;
            }
            --st;
            nrc=0;
            for(dr=n;nrc<cat;--dr)
            {
                if(v[dr]==val)
                    ++nrc;
            }
            ++dr;
            for(i=0;i<=200;++i)
                fv[i]=0;
            mx=0;
            for(i=st+1;i<dr;++i)
                fv[v[i]]++,mx=max(mx,fv[v[i]]);
            rz=max(rz,mx+cat*2);
            while(cat>0)
            {
                cat--;
                fv[v[st]]++,mx=max(mx,fv[v[st]]);
                fv[v[dr]]++,mx=max(mx,fv[v[dr]]);
                --st;
                ++dr;
                while(st>=1 && v[st]!=val)
                {
                    fv[v[st]]++,mx=max(mx,fv[v[st]]);
                    --st;
                }
                while(dr<=n && v[dr]!=val)
                {
                    fv[v[dr]]++,mx=max(mx,fv[v[dr]]);
                    ++dr;
                }
                rz=max(rz,mx+cat*2);
            }
        }
        cout<<rz<<'\n';
    }
    return 0;
}