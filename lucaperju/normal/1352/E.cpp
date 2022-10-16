#include <bits/stdc++.h>

using namespace std;
int v[8003],exst[8003];
int sp[8003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            exst[i]=0;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=n;++i)
            sp[i]=sp[i-1]+v[i];
        for(i=1;i<=n;++i)
            for(j=0;j<i-1;++j)
                if(sp[i]-sp[j]<=n)
                    exst[sp[i]-sp[j]]=1;
        int cnt=0;
        for(i=1;i<=n;++i)
            if(exst[v[i]])
                ++cnt;
        cout<<cnt<<'\n';
    }
    return 0;
}