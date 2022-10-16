#include <bits/stdc++.h>

using namespace std;
int v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    int k=0,t,i,j,n,a,b,m,x,y,ok=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            if(v[i]!=0 && (i==n || v[i+1]==0))
                ++cnt;
        }
        cout<<min(cnt,2)<<'\n';
    }
    return 0;
}