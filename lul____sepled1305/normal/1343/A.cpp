#include<bits/stdc++.h>
using namespace std;
long long i,t,k;
long long mp[70];

int main()
{
    cin>>t;
    i=2; k =2;
    while(i<=50)
    {
        k*=2;
        mp[i] = k-1;
        i++;
    }
    while(t--)
    {
        k=2;
        cin>>i;
        while(k<=70)
        {
            if(i%mp[k]==0)
            {
                cout<<i/mp[k]<<"\n";
                break;
            }
            k++;
        }
    }
    return 0;
}