#include <bits/stdc++.h>
using namespace std;
int v[200005],cat[200005];
vector <int> vf[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	long long mxc=0,n,m,a,b,i,j=0,t;
	cin>>n>>m;
	for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=m;++i)
        cin>>cat[i];
    sort(v+1,v+n+1);
    int rz=1;
    for(i=1;i<=n;++i)
    {
        int catam=cat[v[i]];
        int cattrb=n-i+1;
        rz=max(rz,(cattrb-1)/catam+1);
    }
    cout<<rz<<'\n';
    j=1;
    for(i=n;i>=1;--i)
    {
        vf[j].push_back(v[i]);
        ++j;
        if(j>rz)
            j-=rz;
    }
    for(i=1;i<=rz;++i)
    {
        cout<<vf[i].size()<<' ';
        for(j=0;j<vf[i].size();++j)
            cout<<vf[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}