#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,i,j,rz=0,s=0,k,n,m;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        if(n<=7)
        {
            if(n==3)
            {
                cout<<"1 0 0\n";
            }
            else
            if(n==5)
                cout<<"0 1 0\n";
            else if (n==7)
                cout<<"0 0 1\n";
            else if(n==6)
                cout<<"2 0 0\n";
            else
                cout<<"-1\n";
            continue;
        }
        if(n%3==0)
        {
            cout<<n/3<<' '<<"0 0\n";
        }
        if(n%3==1)
        {
            cout<<(n-7)/3<<' '<<"0 1\n";
        }
        if(n%3==2)
        {
            cout<<(n-5)/3<<' '<<"1 0\n";
        }
    }
    return 0;
}