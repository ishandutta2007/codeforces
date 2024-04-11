#include <bits/stdc++.h>
using namespace std;
int v[200005],w[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j,n,t,m,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=k;++i)
            cin>>w[i];
        sort(v+1,v+n+1);
        sort(w+1,w+k+1);
        long long rz=0;
        for(i=1;i<=k;++i)
        {
            if(w[i]==1)
            {
                rz+=v[n];
                rz+=v[n];
                --n;
            }
            else
                break;
        }
        int cat=i;
        int st=1,dr=n;
        for(i=k;i>=cat;--i)
        {
            w[i]--;
            rz+=v[dr--];
            rz+=v[st];
            st+=w[i];
        }
        cout<<rz<<'\n';
    }
    return 0;
}