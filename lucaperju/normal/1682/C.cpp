#include <bits/stdc++.h>

using namespace std;

int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,t,n,s=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        int a=0,b=0,ok=1;
        for(i=n;i>=1;--i)
        {
            if(i==n || v[i]!=v[i+1])
            {
                if(v[i]==v[i-1] || ok)
                {
                    ++a,++b;
                    if(v[i]!=v[i-1])
                        ok=0;
                }
                else if(a<b)
                    ++a;
                else
                    ++b;
            }
        }
        cout<<min(a,b)<<'\n';
    }
}