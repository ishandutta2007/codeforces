#include <bits/stdc++.h>

using namespace std;
char v[103];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,s;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        cin>>(v+1);
        if(b>=0)
        {
            cout<<n*(a+b)<<'\n';
            continue;
        }
        int cnt=0;
        for(int i=1;i<=n;++i)
        {
            if(i==n || v[i]!=v[i+1])
                ++cnt;
        }
        cout<<n*a+(cnt/2+1)*b<<'\n';
    }
    return 0;
}