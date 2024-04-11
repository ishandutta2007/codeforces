#include <bits/stdc++.h>
using namespace std;
int f[63];
int need[63];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,i,j,t;
    cin>>t;
    while(t--)
    {
        for(i=0;i<=60;++i)
            need[i]=f[i]=0;
        cin>>n>>m;
        long long s=0;
        for(i=1;i<=m;++i)
        {
            long long a;
            cin>>a;
            s+=a;
            ++f[(int)log2(a)];
        }
        if(s<n)
        {
            cout<<"-1\n";
            continue;
        }
        for(int i=0;i<=60;++i)
        {
            if(n&1LL)
                ++need[i];
            n>>=1LL;
        }
        for(i=0;i<=60;++i)
            if(need[i] && f[i])
                --f[i],--need[i];
        int cnt=0;
        int cur=0;
        for(i=0;i<=60;++i)
        {
            cur+=f[i];
            if(cur && need[i])
                --need[i],--cur;
            else if(need[i])
            {
                for(j=i+1;j<=60;++j)
                    if(f[j])
                        break;
                for(;j>i;--j)
                {
                    --f[j];
                    f[j-1]+=2;
                    ++cnt;
                }
                --need[i];
            }
            cur>>=1;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}