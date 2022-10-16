
#include <bits/stdc++.h>
using namespace std;
char v[100];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,n,m,k;
    cin>>t;
    while(t--)
    {
        cin>>v;
        n=strlen(v);
        sort(v,v+n);
        cout<<v<<'\n';
    }
    return 0;
}