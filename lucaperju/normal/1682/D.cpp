#include <bits/stdc++.h>

using namespace std;

int n;
char v[200005];
vector<pair<int,int> >rz;
int get(int a)
{
    a+=n;
    while(a>n)
        a-=n;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,t,s=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            cnt+=(v[i]=='1');
        }
        if(cnt%2==1 || cnt==0)
        {
            cout<<"No\n";
            continue;
        }
        for(i=n;i>=1;--i)
            if(v[i]=='1')
                break;
        int pz=i;
        cout<<"YEs\n";
        cnt=0;
        rz.clear();
        for(i=2;i<=n;++i)
        {
            int pzc=pz-2+i;
            if(pzc>n)
                pzc-=n;
            
            if(v[pzc]=='1')
                rz.push_back(make_pair(pzc,pz-1));
            else
            {
                rz.pop_back();
                rz.push_back(make_pair(get(pzc),get(pzc-1)));
                rz.push_back(make_pair(pz-1,pzc));
            }
        }
        for(int i=0;i<rz.size();++i)
            cout<<rz[i].first<<' '<<rz[i].second<<'\n';
        continue;
    }
}