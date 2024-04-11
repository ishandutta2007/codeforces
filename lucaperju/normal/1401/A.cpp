#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(n<k)
            cout<<k-n;
        else
        {
            if(n%2==k%2)
                cout<<0;
            else
                cout<<1;
        }
        cout<<'\n';
    }
}