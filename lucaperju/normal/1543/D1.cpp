#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long k,m=0,i,j,n,l,r,t;
    cin>>t;
    while(t--)
    {
    cin>>n>>k;
    int sc=0;
    for(i=0;i<n;++i)
    {
        cout<<(sc^i)<<'\n';
        cout.flush();
        int a;
        cin>>a;
        if(a==1)
            break;
        sc=i;
    }
    }
    return 0;
}