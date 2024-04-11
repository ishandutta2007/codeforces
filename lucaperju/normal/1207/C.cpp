#include <bits/stdc++.h>

using namespace std;
long long d[200005][2];
char c[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,n,i,j,cnt=0,m,p,h,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        cin>>(c+1);
        d[0][1]=99999999999999LL;
        for(i=1;i<=n;++i)
        {
            if(c[i]=='0' && c[i+1]=='0' || i==n)
            {
                d[i][0]=min(d[i-1][0]+a+b,d[i-1][1]+2LL*a+b);
                d[i][1]=min(d[i-1][0]+2LL*a+2LL*b,d[i-1][1]+a+2LL*b);
            }
            else
            {
                d[i][1]=min(d[i-1][0]+2LL*a+2LL*b,d[i-1][1]+a+2LL*b);
                d[i][0]=99999999999999LL;
            }
        }
        cout<<d[n][0]+b<<'\n';
    }
    return 0;
}