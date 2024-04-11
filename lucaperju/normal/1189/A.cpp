#include <bits/stdc++.h>

using namespace std;
char v[205];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,i,j,sc=0;
    cin>>n>>v;
    for(int i=0;i<n;++i)
    {
        sc+=v[i]-'0';
    }
    if(sc!=n-sc)
    {
        cout<<1<<'\n';
        cout<<v;
        return 0;
    }
    else
    {
        cout<<2<<'\n';
        cout<<v[0]<<' '<<(v+1);
        return 0;
    }
    return 0;
}