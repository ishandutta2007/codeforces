#include <bits/stdc++.h>
using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,i,j,t,k;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            v[i]=a;
            if(a==i)
                ++cnt;
        }
        if(cnt==n)
        {
            cout<<"0\n";
            continue;
        }
        for(i=1;i<=n;++i)
        {
            if(v[i]==i)
                --cnt;
            else
                break;
        }
        for(i=n;i>=1;--i)
            if(v[i]==i)
                --cnt;
            else
                break;
        if(cnt==0)
            cout<<"1\n";
        else
            cout<<"2\n";
    }
    return 0;
}