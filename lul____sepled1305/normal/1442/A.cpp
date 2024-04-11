#include<bits/stdc++.h>
using namespace std;
int T;
 
void solve()
{
    int n,m,i,r,l;
    l = 0, r= 1e6;
    cin>>n;
    bool pass = true;
    for(i=0;i<n;i++)
    {
        cin>>m;
        r = min(m-l,r);
        l = max(m-r,l);
        if(r+l != m || l<0 || r<0)
            pass = false;
    }
    if(pass)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
 
int main()
{
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}