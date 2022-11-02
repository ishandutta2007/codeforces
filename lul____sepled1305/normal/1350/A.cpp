#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    cin>>t;
    while(t--)
    {
        int n,k,i,div;
        bool suc = false;
        cin>>n>>k;
        for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                div = i;
                suc = true;
                break;
            }
        }
        if(!suc)
            div = n;
        if(k==1)
        {
            cout<<n+div<<"\n";
        }
        else
        {
            cout<<n+div+2*(k-1)<<"\n";
        }
    }
}