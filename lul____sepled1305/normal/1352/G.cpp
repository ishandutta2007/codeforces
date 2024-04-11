#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        if(n<4)
            cout<<"-1\n";
        else if(n==4)
            cout<<"3 1 4 2\n";
        else if(n==5)
            cout<<"5 3 1 4 2\n";
        else
        {
            int odd = (n+1)/2;
            while(odd--)
            {
                cout<<2*odd+1<<" ";
            }
            cout<<"4 2 6 ";
            int even = n/2;
            for(i=4;i<=n/2;i++)
                cout<<2*i<<" ";
            cout<<"\n";
        }
    }
}