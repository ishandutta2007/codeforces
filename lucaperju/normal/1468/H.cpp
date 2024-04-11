#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,mod,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>m;
        int ok=0;
        int vst,vdr;
        for(i=1;i<=m;++i)
        {
            int a;
            cin>>a;
            vst=a-i;
            vdr=n-a-(m-i);
            if(vst>=k/2 && vdr>=k/2)
                ok=1;
        }
        if((n-m)%(k-1))
        {
            cout<<"No\n";
            continue;
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"nO\n";
    }
    return 0;
}