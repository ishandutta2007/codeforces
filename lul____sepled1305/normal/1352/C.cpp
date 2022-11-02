#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        long long n,k,rem;
        cin>>n>>k;
        rem = k%(n-1);
        if(rem!=0)
            cout<<n*(k/(n-1))+rem<<"\n";
        else
            cout<<n*(k/(n-1))-1<<"\n";
    }
}