#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i;
        bool prime = true;
        cin>>n;
        for(i=2;i<=sqrt(n);i++)
            if(n%i==0)
            {
                prime = false;
                break;
            }
        if(!prime)
            cout<<n/i<<" "<<n-(n/i);
        else
            cout<<1<<" "<<n-1;
        cout<<"\n";
    }
}