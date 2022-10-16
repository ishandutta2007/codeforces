#include <bits/stdc++.h>

using namespace std;
char v[200005];
int pz[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long i,t,j,k,mx,p,mxx=0,s,q;
    cin>>t;
    while(t--)
    {
        cin>>(v+1);
        int n=strlen(v+1);
        for(i=2;i<=n;++i)
        {
            if(v[i]!=v[i-1])
                pz[i]=i-1;
            else
                pz[i]=pz[i-1];
        }
        long long mx=9999999;
        for(i=1;i<n;++i)
        {
            if(v[i]!=v[i+1] && pz[i]!=0 && v[pz[i]]!=v[i] && v[pz[i]]!=v[i+1])
            {
                mx=min(mx,i+2-pz[i]);
            }
        }
        if(mx==9999999)
            cout<<"0\n";
        else
            cout<<mx<<'\n';
    }
    return 0;
}