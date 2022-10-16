#include <bits/stdc++.h>
using namespace std;
int v[500005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,d,i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        if(v[1]+v[2]>v[n])
            cout<<-1<<'\n';
        else
            cout<<"1 2 "<<n<<'\n';
    }
    return 0;
}