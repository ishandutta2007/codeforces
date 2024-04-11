#include <bits/stdc++.h>
using namespace std;
int rz[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,i,j,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long cur=1,sc=1,cnt=0;
        while(sc!=n)
        {
            if(sc+cur*2+cur*2<=n)
            {
                cur*=2;
                sc+=cur;
                ++cnt;
                rz[cnt]=cur/2;
            }
            else
            {
                if(sc==n)
                {
                    cout<<cnt;
                    break;
                }
                else if(sc+cur*2>=n)
                {
                    cout<<cnt+1;
                    rz[cnt+1]=n-(sc+cur);
                    ++cnt;
                    break;
                }
                else
                {
                    cout<<cnt+2;
                    long long dst=n-sc;
                    rz[cnt+1]=dst/2-cur;
                    rz[cnt+2]=dst%2;
                    cnt+=2;
                    break;
                }
            }
        }
        cout<<'\n';
        for(i=1;i<=cnt;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}