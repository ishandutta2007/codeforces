#include <bits/stdc++.h>
using namespace std;
int v[200005];
char ch[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int s=0,n,i,t,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int m;
        cin>>m;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            m-=a;
        }
        if(m==0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}