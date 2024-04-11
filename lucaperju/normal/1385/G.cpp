#include <bits/stdc++.h>
using namespace std;
int v[200005];
int a[200005],b[200005];
vector<int>pz[200005];
vector<int>rz;
vector<int>v1,v2;
int main()
{
    long long n,m,i,j,x,y,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            v[i]=0;
            pz[i].clear();
        }
        rz.clear();
        for(i=1;i<=n;++i)
        {
            cin>>a[i];
            pz[a[i]].push_back(i);
        }
        for(i=1;i<=n;++i)
        {
            cin>>b[i];
            pz[b[i]].push_back(i);
        }
        for(i=1;i<=n;++i)
        {
            if(pz[i].size()!=2)
            {
                cout<<-1<<'\n';
                break;
            }
        }
        if(i!=n+1)
            continue;
        for(i=1;i<=n;++i)
        {
            if(v[i]==1)
                continue;
            int vlc=a[i];
            int cnt=1;
            v1.clear();
            v2.clear();
          //  v1.push_back(i);
            int pzc=i;
            v2.push_back(i);
            v[i]=1;
            while(vlc!=b[i])
            {
                pzc=pz[vlc][0]+pz[vlc][1]-pzc;
                if(a[pzc]==vlc)
                    v1.push_back(pzc);
                else
                    v2.push_back(pzc);
                vlc=a[pzc]+b[pzc]-vlc;
                v[pzc]=1;
            }
            if(v1.size()<=v2.size())
            {
                for(j=0;j<v1.size();++j)
                    rz.push_back(v1[j]);
            }
            else
            {
                for(j=0;j<v2.size();++j)
                    rz.push_back(v2[j]);
            }
        }
        cout<<rz.size()<<'\n';
        for(i=0;i<rz.size();++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}