#include <bits/stdc++.h>
using namespace std;
int cur[30];
char v[200005];
int rz[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,i,j;
    cin>>n>>v;
    for(i=0;i<n;++i)
    {
        int mx=0;
        for(int j=v[i]-'a'+1;j<='z'-'a'+1;++j)
            mx=max(mx,cur[j]);
        rz[i+1]=mx+1;
        cur[v[i]-'a']=max(cur[v[i]-'a'],mx+1);
    }
    int mx=0;
    for(i=1;i<=n;++i)
        mx=max(mx,rz[i]);
    cout<<mx<<'\n';
    for(i=1;i<=n;++i)
        cout<<rz[i]<<' ';
    return 0;
}