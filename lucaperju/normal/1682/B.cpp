#include <bits/stdc++.h>

using namespace std;

int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,t,n,s=0;
    cin>>t;
    while(t--)
    {
       s=-1;
       cin>>n;
       for(int i=1;i<=n;++i)
       {
            cin>>v[i];
            if(v[i]!=i-1)
            {
                if(s==-1)
                    s=v[i];
                else
                    s=(s&v[i]);
            }
       }
       cout<<s<<'\n';
    } 
}