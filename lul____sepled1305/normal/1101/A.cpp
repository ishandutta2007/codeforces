#include<bits/stdc++.h>
using namespace std;
int n,q,l,m,g,i;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>q>>l>>m;
        if(q>m)
        {
            cout<<m<<"\n";
        }
        else
        {
            cout<<(l/m)*m+m<<"\n";
        }
    }
}