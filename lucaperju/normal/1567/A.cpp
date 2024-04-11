#include <bits/stdc++.h>
using namespace std;
char v[103];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,m,q,n,s=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>v;
        for(i=0;i<n;++i)
        {
            if(v[i]=='U' || v[i]=='D')
                cout<<(char)('U'+'D'-v[i]);
            else
                cout<<v[i];
        }
        cout<<'\n';
    }
    return 0;
}