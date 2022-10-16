#include <bits/stdc++.h>
using namespace std;
char v[200005];
vector<int>vc;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,rz=0,s=0,k,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=0;
        vc.clear();
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            if(i!=1 && v[i]!=v[i-1])
            {
                vc.push_back(cnt);
                cnt=0;
            }
            ++cnt;
        }
        vc.push_back(cnt);
        cnt=0;
        j=0;
        for(i=0;i<vc.size();++i)
        {
            j=max(j,i);
            while(j+1<vc.size() && vc[j]==1)
                ++j;
            if(vc[j]>1)
            {
                --vc[j];
            }
            else
            {
                ++i;
            }
            ++cnt;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}