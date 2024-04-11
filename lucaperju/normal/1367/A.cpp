#include <bits/stdc++.h>

using namespace std;
char v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long t,m,k,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>t;
    while(t--)
    {
        cin>>(v+1);
        n=strlen(v+1);
        for(i=1;i<=n;i+=2)
            cout<<v[i];
        --i;
        if(i<=n)
            cout<<v[i];
        cout<<'\n';
    }
    return 0;
}