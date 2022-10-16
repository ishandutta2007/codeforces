#include <bits/stdc++.h>
using namespace std;
char v[1000003];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i,j;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin>>(v+1);
        int cnt=0;
        for(i=1;i<=n;++i)
            if(v[i]=='*')
                ++cnt;
        cnt=(cnt+1)/2;
        int s=0;
        for(i=1;i<=n;++i)
            if(v[i]=='*')
            {
                ++s;
                if(s==cnt)
                    break;
            }
        cnt=0;
        long long rz=0;
        for(j=i;j>=1;--j)
        {
            if(v[j]=='.')
                ++cnt;
            else
                rz+=cnt;
        }
        cnt=0;
        for(j=i+1;j<=n;++j)
            if(v[j]=='.')
                ++cnt;
            else
                rz+=cnt;
        cout<<rz<<'\n';
    }
}