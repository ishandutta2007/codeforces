#include <bits/stdc++.h>
using namespace std;
int fv[105];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,i,j,k,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<=100;++i)
            fv[i]=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            ++fv[a];
        }
        int rz=0;
        int cnt=2;
        for(i=0;cnt>0 && i<=100;++i)
        {
            if(fv[i]==0)
            {
                if(cnt==2)
                    rz=2*i;
                if(cnt==1)
                    rz+=i;
                cnt=0;
            }
            if(fv[i]==1)
            {
                if(cnt==2)
                    rz=i,cnt=1;
            }
        }
        cout<<rz<<'\n';
    }
    return 0;
}