#include <bits/stdc++.h>
using namespace std;
int v[200003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,t,p,j;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n+=2;
        long long s=0;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        for(i=1;i<=n-2;++i)
            s+=v[i];
        if(s==v[n-1] || s==v[n])
        {
            for(i=1;i<=n-2;++i)
                cout<<v[i]<<' ';
            cout<<'\n';
            continue;
        }
        s+=v[n-1];
        int pz;
        for(pz=1;pz<=n-2;++pz)
        {
            if(s-v[pz]==v[n])
                break;
        }
        if(pz==n-1)
        {
            cout<<-1<<'\n';
            continue;
        }
        for(i=1;i<=n-1;++i)
            if(i!=pz)
                cout<<v[i]<<' ';
        cout<<'\n';
    }
	return 0;
}