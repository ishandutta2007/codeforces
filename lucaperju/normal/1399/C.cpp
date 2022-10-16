#include <bits/stdc++.h>
using namespace std;
int v[105];
int dp[55][55][105];
int main()
{
    long long t,n,m,i,j,x,y,k,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        int bst=0;
        for(i=1;i<=n;++i)
        {
            for(j=i+1;j<=n;++j)
            {
                int sc=v[i]+v[j];
                int cntc=1;
                int cj=j;
                int ci=i;
                --i;
                ++j;
                while(i>=1 && j<=n)
                {
                    if(v[i]+v[j]==sc)
                    {
                        ++cntc;
                        --i;
                        ++j;
                    }
                    else if(v[i]+v[j]>sc)
                        --i;
                    else
                        ++j;
                }
                if(cntc>bst)
                {
                    bst=cntc;
                }
                i=ci;
                j=cj;
            }
        }
        cout<<bst<<'\n';
    }
    return 0;
}