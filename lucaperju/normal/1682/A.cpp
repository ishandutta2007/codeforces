#include <bits/stdc++.h>

using namespace std;

char v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,t,n,s=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>(v+1);
        int cnt=0;
        int mid=(n/2)+1;
        for(i=mid;i<=n && v[i]==v[mid];++i,++cnt);
        for(i=mid-1;i>=1 && v[i]==v[mid];--i,++cnt);
        cout<<cnt<<'\n';
    } 
}