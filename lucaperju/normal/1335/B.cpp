#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j=0,n,t,mx=0,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        for(i=1;i<=n;++i)
        {
            int pz=(i-1)%a+1;
            if(pz<=b)
                cout<<(char)('a'+pz-1);
            else
                cout<<(char)('a'+b-1);
        }
        cout<<'\n';
    }
    return 0;
}