#include <bits/stdc++.h>
using namespace std;
int a[100003],b[100003],c[100003];
int rz[100003];
int eok[100003];
vector<int>v[100003];
int eokt=0;
int main()
{
    long long t,n,i,j,m,k=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        eokt=0;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            eok[i]=0;
            cin>>a[i];
        }
        for(i=1;i<=n;++i)
        {
            cin>>b[i];
            if(a[i]!=b[i])
                v[b[i]].push_back(i);
            eok[b[i]]=i;
        }
        for(i=1;i<=m;++i)
            cin>>c[i];
        int rasp=1;
        for(i=m;i>=1;--i)
        {
            int vlc=c[i];
            if(v[vlc].size())
            {
                int pz=v[vlc][v[vlc].size()-1];
                v[vlc].pop_back();
                rz[i]=pz;
                eokt=pz;
                continue;
            }
            if(eokt || eok[vlc])
            {
                if(eok[vlc])
                    eokt=eok[vlc];
                rz[i]=eokt;
                continue;
            }
            rasp=0;
            break;
        }
        for(i=1;i<=n;++i)
            if(v[i].size())
                rasp=0;
        if(rasp)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        if(rasp){
            for(i=1;i<=m;++i)
                cout<<rz[i]<<' ';
         cout<<'\n';
        }

    }
    return 0;
}