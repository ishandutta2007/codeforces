#include <bits/stdc++.h>
using namespace std;
vector<int>rz[55];
int v[55];
int cv[55],k;
void execute(int n)
{
    int r=n,l=1;
    for(int i=0;i<rz[k].size();++i)
    {
        for(int j=l;j<=l-1+rz[k][i];++j)
            cv[r-rz[k][i]+j-l+1]=v[j];
        r-=rz[k][i];
        l+=rz[k][i];
    }
    for(int i=1;i<=n;++i)
        v[i]=cv[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,i,j,s=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<n;++i)
    {
        if(i%2==1)
        {
            if(i==1 && v[1]==1)
                continue;
            ++k;
            for(j=1;j<=n;++j)
                if(v[j]==i)
                    break;
            if(j!=1)
                rz[k].push_back(j-1);
            rz[k].push_back(n-(i-1)-(j-1));
            for(j=1;j<i;++j)
                rz[k].push_back(1);
        }
        else
        {
            ++k;
            for(j=1;j<i;++j)
                rz[k].push_back(1);
            for(j=1;j<=n;++j)
                if(v[j]==i)
                    break;
            rz[k].push_back(j-(i-1));
            if(n-j)
                rz[k].push_back(n-j);
        }
        execute(n);
    }
    if(v[1]!=1)
    {
        ++k;
        for(i=1;i<=n;++i)
            rz[k].push_back(1);
    }
    cout<<k<<'\n';
    for(i=1;i<=k;++i)
    {
        cout<<rz[i].size()<<' ';
        for(j=0;j<rz[i].size();++j)
            cout<<rz[i][j]<<' ';
        cout<<'\n';
    }
}