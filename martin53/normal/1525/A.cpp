#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        int k;
        cin>>k;

        cout<<100/__gcd(k,100-k)<<endl;
    }

    return 0;
}