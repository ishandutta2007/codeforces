#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        int n;
        cin>>n;

        cout<<ceil(sqrt(n-0.1))<<endl;
    }

    return 0;
}